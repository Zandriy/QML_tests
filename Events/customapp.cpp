#include "customapp.h"
#include "customevent.h"
#include <QDebug>

CustomApp::CustomApp(int &argc, char **argv)
    : QGuiApplication(argc, argv)
{

}

bool CustomApp::notify(QObject *receiver, QEvent *event)
{
    Q_UNUSED(receiver)
    if (event->type() == CustomEvent::customEvent)
    {
        CustomEvent* e = static_cast<CustomEvent*>(event);
        qDebug() << "Custom event " << e->name() << " pass notify()";
    }
    return QGuiApplication::notify(receiver, event);
}
