#ifndef SUBJECT_H
#define SUBJECT_H

#include <string>
#include <fstream>
#include <list>
#include "Observer.h"
#include <algorithm>


using namespace std;

class Subject
{
    list<Observer*> _observers;
    typedef list<Observer*>::iterator _iterator;

    string temp;
    string tempOrt;
    string tempTemperatur;
    ifstream Myfile;
    int i;
    string line;

public:
    void Attach(Observer* observer);
    void Detach(Observer* observer);
    void Notify(string data);
    void Notify();
    void Download();
    void Parse();

};

#endif // SUBJECT_H
