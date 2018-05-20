#ifndef CUSTOMITEM_H
#define CUSTOMITEM_H

#include <QQuickItem>

class CustomItem : public QQuickItem
{
    Q_OBJECT
public:
    CustomItem();

    bool eventFilter(QObject *watched, QEvent *event) override;
    bool event(QEvent *event) override;
    void customEvent(QEvent *event) override;
signals:

public slots:
    void sendCustomEvent();
    void postCustomEvent();
};

#endif // CUSTOMITEM_H
