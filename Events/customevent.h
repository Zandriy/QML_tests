#ifndef CUSTOMEVENT_H
#define CUSTOMEVENT_H

#include <QEvent>
#include <QString>

class CustomEvent : public QEvent
{
public:    
    static const QEvent::Type customEvent = QEvent::Type(QEvent::User + 1);

    CustomEvent(QString name);
    QString name();
private:
    QString m_name;
};

#endif // CUSTOMEVENT_H
