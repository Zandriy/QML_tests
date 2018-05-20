#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "customapp.h"
#include "customitem.h"
#include "custommodalitem.h"

int main(int argc, char *argv[])
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    CustomApp app(argc, argv);

    qmlRegisterType<CustomItem>("custom.app", 1, 0, "CustomItem");
    qmlRegisterType<CustomModalItem>("custom.app", 1, 0, "CustomModalItem");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
