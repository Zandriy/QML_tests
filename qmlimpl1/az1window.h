#ifndef AZWINDOW_H
#define AZWINDOW_H

#include <QQuickWindow>

namespace AZ1 {

class Window : public QQuickWindow
{
    Q_OBJECT
public:
    Window(QWindow* parent = Q_NULLPTR);

signals:

public slots:
};

} // namespace AZ1

#endif // AZWINDOW_H
