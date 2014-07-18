#include "observerlinien.h"
#include "mainwindow.h"

ObserverLinien::ObserverLinien(QWidget *parent, QwtPlotCurve* linien, string name):QwtPlot(parent)
{
    this->linien = linien;
    this->name = name;
}

void ObserverLinien::Update(string data)
{
    if(data[0] >= 48 && data[0] <= 57)
    {

        stringstream stringtodouble;
        stringtodouble << data;
        stringtodouble >> temperatur[i];
        AnzahlTemp[i]=i;

        i++;
        //cout<<temperatur << endl;


    }

 /*   if(data[0] >= 65 && data[0] <= 90)
    {
        QString title(data.c_str());
        titel += title;
        cout << data << endl;
    }*/



}

void ObserverLinien::Update()
{
    linien->setRawSamples(AnzahlTemp,temperatur,i);
i=0;

}

