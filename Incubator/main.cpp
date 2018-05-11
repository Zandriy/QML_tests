#include <QApplication>
#include <QQmlApplicationEngine>

#include "mainwindow.h"
#include "mainincubationcontroller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    QQmlApplicationEngine engine;
    MainIncubationController incubator;

    engine.setIncubationController(&incubator);
    qmlRegisterType<MainWindow>("com.main.ui", 1, 0, "MainWindow");
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));

    return app.exec();
}
