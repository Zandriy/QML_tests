#include "customevent.h"

CustomEvent::CustomEvent(QString name)
    : QEvent{customEvent}
    , m_name{name}
{

}

QString CustomEvent::name()
{
    return m_name;
}
