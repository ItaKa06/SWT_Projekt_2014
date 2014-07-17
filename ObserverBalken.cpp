#include "ObserverBalken.h"


ObserverBalken::ObserverBalken(std::string name)
{
    this->name = name;
	
}


void ObserverBalken::Update()
{
    
    //testausgabe auf der console
    std::cout << "Diagramm "<< name << " geaendert " << "\n";
}
