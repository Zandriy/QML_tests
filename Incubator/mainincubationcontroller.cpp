#include "mainincubationcontroller.h"
#include <QDebug>

MainIncubationController::MainIncubationController()
{
    startTimer(1000);
}

void MainIncubationController::timerEvent(QTimerEvent *e)
{
    Q_UNUSED(e);
    if(incubatingObjectCount())
    {
        m_flag = true;
        incubateWhile(&m_flag, 1);
    }
}

void MainIncubationController::incubatingObjectCountChanged(int incubatingObjectCount)
{
    Q_UNUSED(incubatingObjectCount);
    m_flag = false;
}
