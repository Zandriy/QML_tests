#include "testwindow.h"
#include <QDebug>
#include <QtTest/QTest>
#include "tst_GestureArea.h"

TestWindow::TestWindow()
{
    QObject::connect(this, &TestWindow::activeChanged, this, &TestWindow::test);
}

void TestWindow::test()
{
    QObject::disconnect(this, &TestWindow::activeChanged, this, &TestWindow::test);

    tst_GestureArea myTest(this);

    int result1 = QTest::qExec(&myTest, 0, nullptr);
}
