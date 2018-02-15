#ifndef SLICE_H
#define SLICE_H

#include <QQuickPaintedItem>
#include <QColor>

namespace AZ2 {

class Slice : public QQuickPaintedItem
{
    Q_OBJECT
    Q_PROPERTY(QColor color READ color WRITE setColor)
    Q_PROPERTY(int fromAngle READ fromAngle WRITE setFromAngle)
    Q_PROPERTY(int angleSpan READ angleSpan WRITE setAngleSpan)

private:
    QColor m_color;
    int m_fromAngle;
    int m_angleSpan;

public:
    Slice(QQuickItem* parent = nullptr);

    QColor color() const;
    void setColor(const QColor &color);

    int fromAngle() const;
    void setFromAngle(int angle);

    int angleSpan() const;
    void setAngleSpan(int span);

    void paint(QPainter *painter) override;

signals:

public slots:
};

} // namespace AZ2

#endif // SLICE_H
