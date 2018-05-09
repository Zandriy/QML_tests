#include "az2slice.h"
#include <QPen>
#include <QPainter>

namespace AZ2 {

Slice::Slice(QQuickItem *parent)
    : QQuickPaintedItem(parent)
{
}

QColor Slice::color() const
{
   return m_color;
}

void Slice::setColor(const QColor &color)
{
   if(color != m_color) {
        m_color = color;
        update();
    }
}

int Slice::fromAngle() const
{
    return m_fromAngle;
}

void Slice::setFromAngle(int angle)
{
    m_fromAngle = angle;
}

int Slice::angleSpan() const
{
    return m_angleSpan;
}

void Slice::setAngleSpan(int span)
{
    m_angleSpan = span;
}

void Slice::paint(QPainter *painter)
{
    QPen pen(m_color, 2);
    painter->setPen(pen);
    painter->setRenderHints(QPainter::Antialiasing, true);
    painter->drawPie(boundingRect().adjusted(1, 1, -1, -1), m_fromAngle * 16, m_angleSpan * 16);
}

} // namespace AZ2
