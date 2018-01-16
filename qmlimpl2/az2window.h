#ifndef AZ2WINDOW_H
#define AZ2WINDOW_H

#include <QQuickView>

namespace AZ2 {

class Window : public QQuickView
{
    Q_OBJECT
public:
    Window(QWindow* parent = Q_NULLPTR);

signals:

public slots:
};

} // namespace AZ2

#endif // AZ2WINDOW_H
