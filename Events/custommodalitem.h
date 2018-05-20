#ifndef CUSTOMMODALITEM_H
#define CUSTOMMODALITEM_H

#include <QQuickItem>

class QEventLoop;

class CustomModalItem : public QQuickItem
{
    Q_OBJECT
public:
    CustomModalItem();
    ~CustomModalItem();

signals:

public slots:
    void makeModal();

private:
    QEventLoop *m_eventLoop;
};

#endif // CUSTOMMODALITEM_H
