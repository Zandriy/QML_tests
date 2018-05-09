#include "az2dia.h"
#include "az2slice.h"

namespace AZ2 {

Dia::Dia(QQuickItem *parent)
    : QQuickItem(parent)
{
}

QString Dia::name() const
{
    return m_name;
}

void Dia::setName(const QString &name)
{
    m_name = name;
}

QQmlListProperty<Slice> Dia::slices()
{
   return QQmlListProperty<Slice>(this, 0, &Dia::append_slice, 0, 0, 0);
}

void Dia::append_slice(QQmlListProperty<Slice> *list, Slice *slice)
{
    Dia *dia = qobject_cast<Dia*>(list->object);
    if(dia)
    {
        slice->setParentItem(dia);
        dia->m_slices.append(slice);
    }
}

} // namespace AZ2
