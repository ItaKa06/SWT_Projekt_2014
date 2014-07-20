#include "observerdaten.h"

ObserverDaten::ObserverDaten(QWidget *parent, string name):QwtPlot(parent)
{
    this->name = name;
}
void ObserverDaten::Update(string data)
{
    //Ãœbergibt Standort + Temperaturdaten an zeile[i]. ACII Werte 48-57 sind Zahlen
    if(data[0] >= 48 && data[0] <= 57)
    {
       temp = temp + ": " + data;
       zeile[ZaehlerVar] = temp.c_str();
       ZaehlerVar++;
    }
    //Ãœbergibt Standort an string temp. ACII Werte 65-90 sind GroÃŸbuchstaben
    if(data[0] >= 65 && data[0] <= 90)
    {
       temp = data;
    }

    //Ãœbergibt Metadaten an zeile[i]. ACII Werte 35 ist #
    if(data[0] == 35)
    {
      zeile[ZaehlerVar] = data.c_str();
      ZaehlerVar++;
    }

}

//Updated Rohdatendiagramm
void ObserverDaten::Update()
{
   ZaehlerVar=0;
   QString temp;

   for(int j=0; j<8;j++)
   {
     temp=temp+"\n\n"+zeile[j];
   }

   //Schriftart fÃ¼r Rohdaten wird formatiert und konfiguriert
   QwtText Daten(temp);
   QFont font;
   font.setBold( true );
   font.setFamily("Comic Sans MS");
   font.setPixelSize(14);
   Daten.setFont( font );
   Daten.setRenderFlags(Qt::AlignLeft | Qt::AlignTop);


   titleItem->setText( Daten );
   titleItem->attach( this );

}
