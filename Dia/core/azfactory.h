#ifndef AZFACTORY_H
#define AZFACTORY_H

namespace AZ {

class Factory
{
public:
    virtual bool createEngine() = 0;
    virtual ~Factory(){}
};

} // namespace AZ

#endif // AZFACTORY_H
