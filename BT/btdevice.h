#ifndef BTDEVICE_H
#define BTDEVICE_H

#include <QObject>

class QBluetoothLocalDevice;
class QString;

class BTDevice : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name)
    Q_PROPERTY(bool active READ isActive NOTIFY onActiveChanged)
    Q_PROPERTY(bool visible READ isVisible NOTIFY onVisibleChanged)
public:
    BTDevice();

public slots:
    void switchPower();
    void switchVisible();

    QString name() const;
    bool isActive() const;
    bool isVisible() const;

signals:
    void onActiveChanged();
    void onVisibleChanged();

private:
    QBluetoothLocalDevice* m_device{nullptr};
    bool m_active{false};
    bool m_visible{false};
};

#endif // BTDEVICE_H
