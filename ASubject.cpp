#include "ASubject.h"
#include <tchar.h>
#include <urlmon.h>
#include <iostream>
#include <fstream> 
#include <Windows.h>
#include <WinInet.h>
#include <stdio.h>
#include <string>  
#include <iostream> 
#include <vector> 
#include <algorithm> 

using namespace std;

#pragma comment(lib, "urlmon.lib")
#pragma comment(lib, "Wininet.lib")



void ASubject::Attach(ObserverInterface *ort)
{
    list.push_back(ort);
}
void ASubject::Detach(ObserverInterface *ort)
{    
    list.erase(std::remove(list.begin(), list.end(), ort), list.end());    
}


void ASubject::Notify(float temp, std::string ort)
{
	
    for(vector<ObserverInterface*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {		
        if(*iter != 0)
        {
            (*iter)->update(temp, ort);
        }
    }	
}

bool equal(const std::string& filename1, const std::string filename2) //Dateien vergleichen
{ 
    std::ifstream f1(filename1.c_str()); //Datei 1
    std::ifstream f2(filename2.c_str()); //Datei 2
    char c1, c2; 
    while(f1.get(c1)) 
    { 
        if(!f2.get(c2)) 
        { 
            return false; 
        } 
        if(c1 != c2) 
        { 
            return false; 
        } 
    } 
    if(f2.get(c2)) 
    { 
        return false; 
    } 
    return true; 
} 


void ASubject::Download() //Diese Methode ist zur sätndigen vergleich der Dateien zuständig
{
	bool loopabort = true;
		do{
			//Download der Datei
			HRESULT hr = URLDownloadToFile ( NULL, _T("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"),_T("myfile.txt"), 0, NULL );
			DeleteUrlCacheEntry(_T("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"));
			Sleep(1000); 
			//nach 1 Sekunde Abstand wird eine 2te Datei zur überprüfung heruntergeladen
			HRESULT br = URLDownloadToFile ( NULL, _T("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"),_T("myfile1.txt"), 0, NULL );
			DeleteUrlCacheEntry(_T("http://tk-labor.iem.thm.de/bti-swt-pa-ss14/hochrechnungen.txt"));
	
	
			if(equal("myfile.txt", "myfile1.txt")) 
			{  
				
				//loopabort = true;//Die Dateien sind gleich.	
			} 
			else 
			{ 
				CopyFileA("myfile1.txt", "myfile.txt",false);
				Notify(34.0f,"Bagdad");
				//loopabort = false;//Die Dateien sind unterschiedlich.	
					
			} 
		}while(loopabort != false);
			

	
}
