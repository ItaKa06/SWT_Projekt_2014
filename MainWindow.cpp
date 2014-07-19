#include "mainwindow.h"
#include "qwt_plot_multi_barchart.h"
#include "qwt_plot_curve.h"
#include <qwt_plot_renderer.h>
#include <qwt_plot_canvas.h>
#include <qwt_column_symbol.h>
#include <qwt_plot_layout.h>
#include <qwt_legend.h>
#include <qwt_scale_draw.h>
#include <qwt_symbol.h>
 #include <QStaticText>


MainWindow::MainWindow(QWidget *parent) :   QMainWindow(parent)
{

    //Chart Objekte
    balkenChart = new QwtPlotMultiBarChart();
    curvenChart = new QwtPlotCurve();

    //Observer Objekte
    balken = new ObserverBalken(this, balkenChart,"Balken");
    linien = new ObserverLinien(this, curvenChart,"Linien");
    daten = new ObserverDaten(this,"Daten");

    //Subjekt erstellen
    sub = new Subject();

    //Observer den Subjekt hinzufÃ¼gen
    sub->Attach(balken);
    sub->Attach(linien);
    sub->Attach(daten);

    //Erster Dateidownload
    sub->Download();

    //Observer den Chart Objekten hinzufÃ¼gen
    balkenChart->attach((QwtPlot*)balken);
    curvenChart->attach((QwtPlot*)linien);

    //Balkendiagramm erstellen
    balken->setAutoFillBackground( true );
    balken->setPalette( Qt::white );
    balken->canvas()->setPalette( QColor( "LemonChiffon" ) );
    balken->setAxisTitle(QwtPlot::yLeft,"Temperatur in Â°C");
    balken->setAxisTitle(QwtPlot::xBottom,"Standort");
    balken->insertLegend( new QwtLegend() );
    balken->setGeometry(450,30,400,400);
    balkenChart->setLayoutPolicy( QwtPlotMultiBarChart::AutoAdjustSamples );
    balkenChart->setSpacing(400);
    balkenChart->setMargin(10);
    balken->enableAxis(QwtPlot::xBottom, false);

    //FÃ¤rbe Balkendiagramm
    static const char *colors[] = { "DarkOrchid", "SteelBlue", "Gold", "green", "red", "pink" };
    const int numBars = sizeof( colors ) / sizeof( colors[0] );
    for ( int i = 0; i < numBars; i++ )
    {
    QwtColumnSymbol *symbol = new QwtColumnSymbol( QwtColumnSymbol::Box );
    symbol->setLineWidth( 2 );
    symbol->setFrameStyle( QwtColumnSymbol::Raised );
    symbol->setPalette( QPalette( colors[i] ) );
    balkenChart->setSymbol( i, symbol );
    }

    //Liniendiagramm erstelln
    linien->setAutoFillBackground( true );
    linien->setPalette( Qt::white );
    linien->canvas()->setPalette( QColor( "LemonChiffon" ) );
    linien->setAxisTitle(QwtPlot::yLeft,"Temperatur in Â°C");
    linien->setAxisTitle(QwtPlot::xBottom,"Standort");
    linien->setAxisScale(QwtPlot::xBottom,0,5,1);
    linien->insertLegend( new QwtLegend() );
    linien->setAxisScale(QwtPlot::yLeft,0,100,10);
    curvenChart->setPen( Qt::darkGreen, 2 );
    QwtSymbol *curvsymbol = new QwtSymbol( QwtSymbol::Ellipse,
        QBrush( Qt::red ), QPen( Qt::red, 2 ), QSize( 5, 5 ) );
    curvenChart->setSymbol( curvsymbol );
    linien->setGeometry(30,30,400,400);

    //Button zum Beenden des Programms
    QWidget * buttonwidget = new QWidget(this);
    QPushButton *ExitButton = new QPushButton(buttonwidget);
    ExitButton->setText(tr("Beenden"));
    setCentralWidget(buttonwidget);
    connect(ExitButton, SIGNAL(clicked()), this, SLOT(close()));
    ExitButton->setGeometry(600, 600, 400,400);
    ExitButton->adjustSize();//Stellt die GrÃ¶ÃŸe des Button automatisch, kann aber auch Ã¼ber setGeometry geregelt werden

    //Rohdaten Zeichnen
    daten->enableAxis(QwtPlot::yLeft, false);
    daten->enableAxis(QwtPlot::xBottom, false);
    daten->setGeometry(870,30,400,400); //int x, int y, int breite, int hoehe

    //Chart- und Labelpositionen festlegen
    linien->setAutoReplot(true);
    balken->setAutoReplot(true);
    daten->setAutoReplot(true);


    //Controller aufrufen und Subjekt Ã¼bergeben
    Controller* controller = new Controller(sub);

}

