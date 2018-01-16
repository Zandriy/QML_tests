#include "az2factory.h"
#include "az2window.h"

namespace AZ2 {

bool Factory::createEngine()
{
    qmlRegisterType<AZ2::Window>("com.az.windows", 1, 0, "AZWindow");

    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (m_engine.rootObjects().isEmpty())
        return false;

    return true;
}

} // namespace AZ2
