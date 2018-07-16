#ifndef BTDEVICE_H
#define BTDEVICE_H

#include <QObject>

class QBluetoothLocalDevice;
class QBluetoothDeviceInfo;
class QBluetoothDeviceDiscoveryAgent;

class BTDevice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(bool active READ isActive NOTIFY activeChanged)
    Q_PROPERTY(bool visible READ isVisible NOTIFY visibleChanged)
    Q_PROPERTY(QStringList connDevices READ connDevices)
    Q_PROPERTY(QStringList foundDevices READ foundDevices)
public:
    BTDevice();

    QString name() const;
    QStringList connDevices() const;
    const QStringList& foundDevices() const;

    Q_INVOKABLE bool isActive() const;
    Q_INVOKABLE bool isVisible() const;

public slots:
    void switchPower();
    void switchVisible();
    void scan();

private slots:
    void deviceFound(const QBluetoothDeviceInfo &device);

signals:
    void activeChanged();
    void visibleChanged();
    void scanFinished();

private:

    QBluetoothLocalDevice* m_device{nullptr};
    QBluetoothDeviceDiscoveryAgent* m_discoveryAgent{nullptr};
    QStringList m_foundDevices;
    bool m_active{false};
    bool m_visible{false};
};

#endif // BTDEVICE_H
