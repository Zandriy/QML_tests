#include "az2factory.h"
#include "az2window.h"
#include "az2item.h"
#include "az2dia.h"
#include "az2slice.h"

namespace AZ2 {

bool Factory::createEngine()
{
    qmlRegisterType<Window>("com.az.windows", 1, 0, "AZWindow");
    qmlRegisterType<Item>("com.az.items", 1, 0, "AZItem");
    qmlRegisterType<Slice>("com.az.items", 1, 0, "AZSlice");
    qmlRegisterType<Dia>("com.az.items", 1, 0, "AZDia");

    m_engine.load(QUrl(QStringLiteral("qrc:/main.qml")));
    if (m_engine.rootObjects().isEmpty())
        return false;

    return true;
}

} // namespace AZ2
