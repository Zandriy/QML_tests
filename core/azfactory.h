#ifndef AZFACTORY_H
#define AZFACTORY_H

namespace AZ {

template<class ConcreteFactory>
class Factory
{
public:
    template<class T>
    T create()
    {
        return m_factory.create<T>();
    }
private:
    ConcreteFactory m_factory;
};

} // namespace AZ

#endif // AZFACTORY_H
