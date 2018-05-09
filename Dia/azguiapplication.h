#ifndef AZGUIAPPLICATION_H
#define AZGUIAPPLICATION_H

#include <QGuiApplication>
#include <core/azfactory.h>
#include <memory>

namespace AZ {

class GuiApplication : public QGuiApplication
{
    Q_OBJECT
public:
    using QGuiApplication::QGuiApplication;
    bool SetupQml();

private:
    std::unique_ptr<Factory> m_factory;

signals:

public slots:
};

} //namespace AZ

#endif // AZGUIAPPLICATION_H
