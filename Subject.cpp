#include "subject.h"
#include <iostream>
#include <urlmon.h>
#include <WinInet.h>
#include <qmessagebox.h>
using namespace std;

void Subject::Attach(Observer *graph)
{
    _observers.push_back(graph);
}

void Subject::Detach(Observer *graph)
{
    _observers.remove(graph);
}

void Subject::Notify(string data)
{
    for(_iterator it = _observers.begin(); it != _observers.end(); ++it)
    {
        (*it)->Update(data);
    }

}

void Subject::Notify()
{

    for(_iterator it = _observers.begin(); it != _observers.end(); ++it)
    {
        (*it)->Update();
    }

}

//Lädt Datei vom Server herunter
void Subject::Download()
{
    QMessageBox DownloadFail;
    QMessageBox DownloadGood;
    DownloadFail.setText((QString)"Fehler beim Download");
    DownloadGood.setText((QString)"Internetverbindung wieder Aktiv, download wieder möglich");

    DeleteUrlCacheEntry(TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"));
    HRESULT hr = URLDownloadToFileW( NULL, TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"),TEXT("\\temp\\myfile.txt"), 0, NULL );

    //Fängt Fehler ab, falls Internetverbindung abbricht oder nicht vorhanden ist
    if(hr == S_OK)
    {
        if(InternetAktiv == false)
        {
            DownloadGood.exec();
        }

        InternetAktiv = true;
    }
    else
    {
        if(InternetAktiv == true)
        {
            DownloadFail.exec();
        }

        InternetAktiv = false;
    }
    Parse();
}


//Ruft Notify auf und übergibt die Daten an die einzelnen Observer
void Subject::Parse()
{

   ifstream DataStream ("\\temp\\myfile.txt");
   QMessageBox FileError;
   FileError.setText((QString)"Datei nicht vorhanden");

   if(DataStream != 0) //Überpruft ob Datei vorhanden
   {
      while( DataStream)
      {
            getline(DataStream, Line);

            Temp = "";
            TempOrt = "";
            TempTemperatur = "";

            if(Line[0] != 35)//Überpruft ob Zeile am Anfang eine # ist
            {
                 for( i=0; Line[i] != ',' ; i++)//Holt sich die Orte aus Datei
                 {
                     TempOrt = TempOrt + Line[i];
                 }

                 Notify(TempOrt);

                 for( i; i < Line.size(); i++)//Holt sich die Temperaturen aus der Datei
                 {
                     if(Line[i] != ',' && Line[i] != ' ')
                     {
                         TempTemperatur = TempTemperatur + Line[i];
                     }
                 }
                 Notify(TempTemperatur);
             }
             else
             {
                 for( i=0; i < Line.size() ; i++)//Holt sich Metadaten aus Datei
                 {
                     Temp = Temp + Line[i];
                 }
                 Notify(Temp);
             }

        }
   }
   else//Falls Datei nicht vorhanden wird ein Fehler ausgegeben
   {
       FileError.exec();
   }

   Notify();

}
