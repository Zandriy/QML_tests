#ifndef AZ2ITEM_H
#define AZ2ITEM_H

#include <QQuickPaintedItem>

namespace AZ2 {

class Item : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QString name READ name WRITE setName)
    Q_PROPERTY(QColor color READ color WRITE setColor NOTIFY colorChanged)
public:
    Item(QQuickItem* parent = nullptr);

    QString name() const;
    void setName(const QString &name);

    QColor color() const;
    void setColor(const QColor &color);

    void paint(QPainter *painter) override;

    Q_INVOKABLE void clear();

signals:
    void colorChanged();
    void cleared();

public slots:

private:
    QString m_name;
    QColor m_color;
};

} // namespace AZ2

#endif // AZ2ITEM_H
