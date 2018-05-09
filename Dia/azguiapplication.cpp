#include "azguiapplication.h"

#define IML1 0
#if IML1
#include "qmlimpl1/az1factory.h"
using AZFactory = AZ1::Factory;
#else
#include "qmlimpl2/az2factory.h"
using AZFactory = AZ2::Factory;
#endif

namespace AZ {

bool GuiApplication::SetupQml()
{
    if(!m_factory)
    {
        m_factory.reset(new AZFactory);
    }

    return m_factory->createEngine();
}

} //namespace AZ
