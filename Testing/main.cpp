#include <QtTest/QTest>
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "tst_GestureArea.h"
#include "testwindow.h"

int main(int argc, char *argv[])
{
    QGuiApplication app(argc, argv);

    qmlRegisterType<TestWindow>("ntg.test.backend", 1, 0, "TestWindow");

    QQmlApplicationEngine engine;
    engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
/*
    TestWindow* wnd = qobject_cast<TestWindow*>(engine.rootObjects().first());
    wnd->setVisible(true);
    app.processEvents();

    tst_GestureArea myTest(wnd);

    int result1 = QTest::qExec(&myTest, argc, argv);

    return result1;
    */
    return app.exec();
}
