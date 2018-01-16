#include "az2window.h"

namespace AZ2 {

Window::Window(QWindow *parent)
    : QQuickView(parent)
{
    setTitle(tr("AZ2 Window"));
}

} //namespace AZ2
