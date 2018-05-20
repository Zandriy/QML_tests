#include "custommodalitem.h"
#include <QEventLoop>

CustomModalItem::CustomModalItem()
    : m_eventLoop{nullptr}
{
    m_eventLoop = new QEventLoop;
}

CustomModalItem::~CustomModalItem()
{
    if (m_eventLoop)
        m_eventLoop->quit();
}

void CustomModalItem::makeModal()
{
    m_eventLoop->exec();
}

