#pragma once
#include <vector>
#include <list> 
#include "ObserverInterface.h" 
  
using namespace std; 
  
class ASubject 
{ 
  
public: 
    void Attach(ObserverInterface* observer); 
    void Detach(ObserverInterface* observer); 
    void Notify(float temp, std::string ort); 
	void Download();
  
private: 
	std::vector<ObserverInterface*> list;
  
  
protected: 
    // Durch protected-Konstruktor wird diese Klasse abstrakt 
    ASubject() {}; 
  
};
