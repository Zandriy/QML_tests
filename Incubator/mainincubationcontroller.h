#ifndef MAININCUBATIONCONTROLLER_H
#define MAININCUBATIONCONTROLLER_H

#include <QObject>
#include <QQmlIncubationController>

class MainIncubationController : public QObject, public QQmlIncubationController
{
    Q_OBJECT
public:
    explicit MainIncubationController();

protected:
    void timerEvent(QTimerEvent *e) override;
    void incubatingObjectCountChanged(int incubatingObjectCount) override;

private:
    bool m_flag { true };

signals:

public slots:
};

#endif // MAININCUBATIONCONTROLLER_H
