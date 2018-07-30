#ifndef TST_GESTUREAREA_H
#define TST_GESTUREAREA_H

#include <QObject>

class QQuickWindow;
class TestWindow;

class tst_GestureArea : public QObject
{
    Q_OBJECT

    TestWindow* m_wnd{nullptr};

public:
    tst_GestureArea(TestWindow* wnd);

private:
    void initTestCase();
    void cleanupTestCase();
private slots:
    void init(); // needs to be under private slots
    void cleanup(); // needs to be under private slots

    void testcase();
    void ppptestcase();
};

#endif // TST_GESTUREAREA_H
