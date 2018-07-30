#include "tst_GestureArea.h"
#include <QtTest/QTest>
#include <QDebug>
#include "testwindow.h"

tst_GestureArea::tst_GestureArea(TestWindow *wnd)
    : m_wnd{wnd}
{

}

void tst_GestureArea::initTestCase()
{
    QVERIFY2(m_wnd, "No Test Window Created");
    //qDebug("initTestCase()");
}

void tst_GestureArea::cleanupTestCase()
{
    //qDebug("cleanupTestCase()");
}

void tst_GestureArea::init()
{
    //qDebug("init()");
}

void tst_GestureArea::cleanup()
{
    //qDebug("cleanup()");
}

void tst_GestureArea::testcase()
{
    QTouchDevice *dev = QTest::createTouchDevice();
    QTest::QTouchEventSequence tes =  QTest::touchEvent(m_wnd, dev);
    tes.press(0, QPoint(100, 100));
    tes.commit(true);
    tes.release(0, QPoint(100, 170));
    tes.commit(true);
    //qDebug("testcase()");
}

void tst_GestureArea::ppptestcase()
{
    //qDebug("ppptestcase()");
}
