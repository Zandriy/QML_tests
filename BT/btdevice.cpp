#include "btdevice.h"

#include <QBluetoothLocalDevice>
#include <QBluetoothDeviceDiscoveryAgent>
#include <QBluetoothServiceDiscoveryAgent>
#include <QStringList>
#include <QString>

#include <QDebug>

BTDevice::BTDevice()
    : m_device{new QBluetoothLocalDevice{this}}
    , m_devDiscoveryAgent{new QBluetoothDeviceDiscoveryAgent{this}}
    , m_serviceDiscoveryAgent{new QBluetoothServiceDiscoveryAgent{this}}
{
    connect(m_devDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::deviceDiscovered, this, &BTDevice::deviceFound);
    connect(m_devDiscoveryAgent, &QBluetoothDeviceDiscoveryAgent::finished, this, &BTDevice::scanDevicesFinished);
    connect(this, &BTDevice::activeChanged, this, &BTDevice::visibleChanged);

    connect(m_serviceDiscoveryAgent, &QBluetoothServiceDiscoveryAgent::serviceDiscovered, this, &BTDevice::serviceFound);
    connect(m_serviceDiscoveryAgent, &QBluetoothServiceDiscoveryAgent::finished, this, &BTDevice::scanServicesFinished);
}

void BTDevice::switchPower()
{
    if(!m_device->isValid())
    {
        return;
    }
    if(!m_active)
    {
        m_device->powerOn();
        m_active = true;
        if(m_visible)
        {
            m_device->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
        }
    }
    else
    {
        m_device->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
        m_active = false;
    }
    emit activeChanged();
}

void BTDevice::switchVisible()
{
    if(!m_active)
    {
        return;
    }
    if(!m_visible)
    {
        m_device->setHostMode(QBluetoothLocalDevice::HostDiscoverable);
        m_visible = true;
    }
    else
    {
        m_device->setHostMode(QBluetoothLocalDevice::HostDiscoverableLimitedInquiry);
        m_visible = false;
    }
    emit visibleChanged();
}

void BTDevice::scanDevices()
{
    if(!m_active)
    {
        return;
    }
    m_foundDevices.clear();
    m_devDiscoveryAgent->start();
}

void BTDevice::scanServices()
{
    if(!m_active)
    {
        return;
    }
    m_foundServices.clear();
    m_serviceDiscoveryAgent->start(QBluetoothServiceDiscoveryAgent::FullDiscovery);
}

void BTDevice::deviceFound(const QBluetoothDeviceInfo &device)
{
    m_foundDevices.push_back(device.address().toString());
}

void BTDevice::serviceFound(const QBluetoothServiceInfo &service)
{
    m_foundServices.push_back(service.serviceName() + " | " + service.serviceUuid().toString());
}

QString BTDevice::name() const
{
    if(m_active)
    {
        return m_device->name();
    }
    else
    {
        return "No Valid BT Device";
    }
}

bool BTDevice::isActive() const
{
    return m_active;
}

bool BTDevice::isVisible() const
{
    return m_active && m_visible;
}

QStringList BTDevice::connDevices() const
{
    if(!m_active)
    {
        return QStringList{};
    }
    QList<QBluetoothAddress> remotes;
    remotes = m_device->connectedDevices();
    QStringList remotesStr;
    for(auto& r : remotes)
    {
        remotesStr.push_back(r.toString());
    }
    return remotesStr;
}

const QStringList &BTDevice::foundDevices() const
{
    return m_foundDevices;
}

const QStringList &BTDevice::foundServices() const
{
    return m_foundServices;
}
