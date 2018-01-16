#ifndef AZ1GUIAPPLICATION_H
#define AZ1GUIAPPLICATION_H

#include <QGuiApplication>
#include <QQmlApplicationEngine>

namespace AZ1 {

class GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    using QGuiApplication::QGuiApplication;
    bool SetupQml();

private:
    QQmlApplicationEngine m_engine;

signals:

public slots:
};

} //namespace AZ1

#endif // AZ1GUIAPPLICATION_H
