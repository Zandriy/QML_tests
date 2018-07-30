#ifndef TESTWINDOW_H
#define TESTWINDOW_H

#include <QQuickWindow>

class TestWindow : public QQuickWindow
{
    Q_OBJECT
public:
    TestWindow();

signals:

public slots:
    void test();
};

#endif // TESTWINDOW_H
