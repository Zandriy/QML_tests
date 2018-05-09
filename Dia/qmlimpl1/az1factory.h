#ifndef AZ1FACTORY_H
#define AZ1FACTORY_H

#include "core/azfactory.h"
#include <QQmlApplicationEngine>

namespace AZ1 {

class Factory : public AZ::Factory
{
public:
    bool createEngine() override;
private:
    QQmlApplicationEngine m_engine;
};

} // namespace AZ1

#endif // AZ1FACTORY_H
