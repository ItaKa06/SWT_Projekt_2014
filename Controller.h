#ifndef CONTROLLER_H
#define CONTROLLER_H
#include <QTimer>
#include "subject.h"

class Controller: public QObject
{
    Q_OBJECT

public:
    Controller(Subject* sub);
    ~Controller();
    QTimer *timer;
private:
    Subject* sub;
public slots:
    void TimerUpdate();
};

#endif // CONTROLLER_H
