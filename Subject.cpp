#include "subject.h"
#include <iostream>
#include <urlmon.h>
#include <WinInet.h>
#include <wininet.h>
#include <qt_windows.h>
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
    for(_iterator it = _observers.begin(); it != _observers.end(); ++it){
            (*it)->Update(data);
    }

}

void Subject::Notify()
{


    for(_iterator it = _observers.begin(); it != _observers.end(); ++it){
            (*it)->Update();
    }

}


void Subject::Download()
{
    //hr = URLDownloadToFile (0, Url, File, 0, 0);
    DeleteUrlCacheEntry(TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"));
    HRESULT hr = URLDownloadToFileW( NULL, TEXT("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"),TEXT("myfile.txt"), 0, NULL );

    Parse();

}





void Subject::Parse()
{
   ifstream dataStream ("C:\\Users\\Elvis\\Desktop\\build-SWT-Desktop_Qt_5_2_1_MinGW_32bit_qt_521-Debug\\myfile.txt");

    while( dataStream)
    {
        getline(dataStream, line);
        //if(line == "")
         //   return;
        temp = "";
        tempOrt = "";
        tempTemperatur = "";
        if(line[0] != 35)
        {
            for( i=0; line[i] != ',' ; i++)
            {
                tempOrt = tempOrt + line[i];
            }
            Notify(tempOrt);
            //cout << tempOrt << endl;

            for( i; i < line.size(); i++)
            {
                if(line[i] != ',' && line[i] != ' ')
                {
                    tempTemperatur = tempTemperatur + line[i];
                }
            }
            Notify(tempTemperatur);
            //cout << tempTemperatur << endl;
        }
        else
        {
            for( i=0; i < line.size() ; i++)
            {
                temp = temp + line[i];
            }
            Notify(temp);
            //cout << temp << endl;
        }

    }

    Notify();
}
