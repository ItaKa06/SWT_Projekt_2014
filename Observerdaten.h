#ifndef OBSERVERBALKEN_H
#define OBSERVERBALKEN_H
#include "Observer.h"
#include "Subject.h"
#include <iostream>
#include <string>
#include <qwidget.h>
#include <qwt_plot_multi_barchart.h>
#include <qwt_plot.h>
#include <qwt_text_label.h>
#include <sstream>
#include <string>
using namespace std;

class ObserverBalken : public QwtPlot, public Observer
{
private:
    //Subject* subject; // Dieses Objekt hÃ¤lt die Daten (=notifier)
    QwtPlotMultiBarChart* ObsBalken;
    string name;

public:
    void Update(string data);
    void Update();
    ObserverBalken(QWidget *parent, QwtPlotMultiBarChart* balken, string name);

    QVector< QVector<double> >series;
    QVector<double> values;
    QList<QwtText> ListStandorte;

    //ObserverBalken();
};

#endif // OBSERVERBALKEN_H
