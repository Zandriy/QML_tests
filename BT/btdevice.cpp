#include "btdevice.h"

#include <QBluetoothLocalDevice>

#include <QDebug>

BTDevice::BTDevice()
    : m_device{new QBluetoothLocalDevice}
{

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
    }
    else
    {
        m_active = false;
    }
    emit onActiveChanged();
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
        m_device->setHostMode(QBluetoothLocalDevice::HostPoweredOff);
        m_visible = false;
    }
    emit onVisibleChanged();
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
    return m_visible && m_active;
}
