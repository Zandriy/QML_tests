#include "az1window.h"

namespace AZ1 {

Window::Window(QWindow *parent)
    : QQuickWindow(parent)
{
    setTitle(tr("AZ1 Window"));
}

} //namespace AZ1
