#ifndef OBSERVERDATEN_H
#define OBSERVERDATEN_H

#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <string>
#include <qwidget.h>
#include <qwt_plot.h>
#include <qwt_plot_textlabel.h>

class ObserverDaten :  public QwtPlot, public Observer
{
private:
    //Subject* subject; // Dieses Objekt hÃ¤lt die Daten (=notifier)
    string name;
    QString zeile[100];
    QwtPlotTextLabel *titleItem = new QwtPlotTextLabel();
    int ZaehlerVar = 0;
    string temp;

public:
    void Update(string data);
    void Update();
    ObserverDaten(QWidget *parent,string name);

};

#endif // OBSERVERBALKEN_H
