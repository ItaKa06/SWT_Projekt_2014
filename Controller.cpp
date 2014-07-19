#include "controller.h"
#include "subject.h"
#include "ObserverBalken.h"
#include "mainwindow.h"
#include <QApplication>



Controller::Controller(Subject* sub)
{
    this->sub = sub;


    timer = new QTimer(this);
    connect(timer,SIGNAL(timeout()), this, SLOT(TimerUpdate()));
    timer->start(1000);

}


Controller::~Controller()
{
    delete sub;
}


void Controller::TimerUpdate()
{
    //Download aufrufen
    sub->Download();
}
