#ifndef AZ2FACTORY_H
#define AZ2FACTORY_H

#include "core/azfactory.h"
#include <QQmlApplicationEngine>

namespace AZ2 {

class Factory : public AZ::Factory
{
public:
    bool createEngine() override;
private:
    QQmlApplicationEngine m_engine;
};

} // namespace AZ2

#endif // AZ2FACTORY_H
