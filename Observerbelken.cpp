#include "observerbalken.h"
#include "mainwindow.h"



ObserverBalken::ObserverBalken(QWidget *parent, QwtPlotMultiBarChart* balken, string name):QwtPlot(parent)
{
    this->balken = balken;
    this->name = name;
}

void ObserverBalken::Update(string data)
{

    if(data[0] >= 48 && data[0] <= 57)
    {

        double temperatur;
        stringstream stream;
        stream << data;
        stream >> temperatur;
        values+=temperatur;
         //cout << temperatur << endl;
    }

    if(data[0] >= 65 && data[0] <= 90)
    {
        QString title(data.c_str());
        titel += title;
        //cout << data << endl;
    }


}

void ObserverBalken::Update()
{
    series+=values;
    balken->setSamples(series);
    balken->setBarTitles(titel);
    series.clear();
    values.clear();
}
