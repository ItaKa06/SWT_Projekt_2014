#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "observerbalken.h"
#include "observerdaten.h"
#include "observerlinien.h"
#include <qwt_plot_grid.h>
#include "subject.h"
#include <qpushbutton.h>
#include "controller.h"
#include <qwt_plot.h>

class QwtPlotMultiBarChart;
class QListWidget;

class MainWindow : public QMainWindow
{   
public:
    MainWindow(QWidget * = NULL);
    QwtPlotMultiBarChart *balkenChart;
    QwtPlotCurve *curvenChart;
    ObserverBalken *balken;
    ObserverLinien *linien;
    ObserverDaten *daten;
    Subject *sub;
};

#endif // MAINWINDOW_H
