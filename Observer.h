#ifndef OBSERVER_H
#define OBSERVER_H
#include <string>

using namespace std;

class MainWindow;

class IObserver
{
public:
     virtual void Update(string data) = 0;
     virtual void Update() = 0;
};

#endif // OBSERVER_H
