#include "customitem.h"
#include "customevent.h"
#include <QDebug>

CustomItem::CustomItem()
{
    qApp->installEventFilter(this);
}

bool CustomItem::eventFilter(QObject *watched, QEvent *event)
{
    Q_UNUSED(watched)
    if (event->type() == CustomEvent::customEvent)
    {
        CustomEvent* e = static_cast<CustomEvent*>(event);
        qDebug() << "Custom event " << e->name() << " pass eventFilter()";
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "MouseButtonPress event pass eventFilter()";
    }

    return QQuickItem::eventFilter(watched, event);
}

bool CustomItem::event(QEvent *event)
{
    if (event->type() == CustomEvent::customEvent)
    {
        CustomEvent* e = static_cast<CustomEvent*>(event);
        qDebug() << "Custom event " << e->name() << " pass event()";
    }
    else if (event->type() == QEvent::MouseButtonPress)
    {
        qDebug() << "MouseButtonPress event pass event()";
    }

    return QQuickItem::event(event);
}

void CustomItem::customEvent(QEvent *event)
{
    if (event->type() == CustomEvent::customEvent)
    {
        CustomEvent* e = static_cast<CustomEvent*>(event);
        qDebug() << "Custom event " << e->name() << " pass customEvent()";
    }
    QQuickItem::customEvent(event);
}

void CustomItem::sendCustomEvent()
{
    CustomEvent event("Send Event");
    qApp->sendEvent(this, &event);
}

void CustomItem::postCustomEvent()
{
    qApp->sendEvent(this, new CustomEvent("Post Event"));
}
