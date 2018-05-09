#include "az2item.h"
#include <QPen>
#include <QPainter>

namespace AZ2 {

Item::Item(QQuickItem* parent)
    : QQuickPaintedItem(parent)
{

}

QString Item::name() const
{
    return m_name;
}

void Item::setName(const QString &name)
{
    m_name = name;
}

QColor Item::color() const
{
    return m_color;
}

void Item::setColor(const QColor &color)
{
    if(color != m_color) {
        m_color = color;
        update();
        emit colorChanged();
    }
}

void Item::paint(QPainter *painter)
{
    QPen pen(m_color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), 90 * 16, 290 * 16);
}

void Item::clear()
{
   setColor(QColor(Qt::transparent));
   update();

   emit cleared();
}

} // namespace AZ2
