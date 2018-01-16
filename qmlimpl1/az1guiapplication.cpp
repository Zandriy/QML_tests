#include "az1guiapplication.h"
#include "qmlimpl1/az1window.h"

namespace AZ1 {

bool GuiApplication::SetupQml()
{
    qmlRegisterType<AZ1::Window>("com.az.windows", 1, 0, "AZWindow");

    m_engine.load(QUrl(QStringLiteral("qrc:/qmlres1/qmlres1/main.qml")));
    if (m_engine.rootObjects().isEmpty())
        return false;

    return true;
}

} //namespace AZ1
