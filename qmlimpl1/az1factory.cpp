#include "az1factory.h"
#include "az1window.h"

namespace AZ1 {

bool Factory::createEngine()
{
    qmlRegisterType<AZ1::Window>("com.az.windows", 1, 0, "AZWindow");

    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (m_engine.rootObjects().isEmpty())
        return false;

    return true;
}

} // namespace AZ1
