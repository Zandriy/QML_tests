#ifndef CUSTOMAPP_H
#define CUSTOMAPP_H

#include <QGuiApplication>


class CustomApp : public QGuiApplication
{
public:
    CustomApp(int &argc, char **argv);
protected:
    bool notify(QObject *receiver, QEvent *event) override;
};

#endif // CUSTOMAPP_H
