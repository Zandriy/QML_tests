#include "qmlimpl1/az1guiapplication.h"
#include <iostream>
#include <exception>

int main(int argc, char *argv[])
try
{
#if defined(Q_OS_WIN)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    AZ1::GuiApplication app(argc, argv);
    if(!app.SetupQml())
        return -1;

    return app.exec();
}
catch(std::exception& err)
{
    std::cerr << "Error: " << err.what() << std::endl;
    return -1;
}
catch(...)
{
    std::cerr << "Unknown Error" << std::endl;
    return -1000;
}
