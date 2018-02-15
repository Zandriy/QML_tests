#ifndef DIA_H
#define DIA_H

#include <QQuickItem>

namespace AZ2 {

class Slice;

class Dia : public QQuickItem
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<AZ2::Slice> slices READ slices)
    Q_PROPERTY(QString name READ name WRITE setName)

private:
    QString m_name;
    QList<Slice*> m_slices;

public:
    Dia(QQuickItem* parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    QQmlListProperty<Slice> slices();
private:
    static void append_slice(QQmlListProperty<Slice> *list, Slice *slice);

signals:

public slots:

};

} // namespace AZ2

#endif // DIA_H
