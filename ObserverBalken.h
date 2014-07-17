#pragma once
#include <iostream>
#include <string>
#include "IObserver.h"

class ObserverBalken : IObserver
{
    std::string name;
public:
	ObserverBalken(std::string n); 
	void Update();   
};
