#pragma once
#include <vector>
#include <list>
#include "IObserver.h"

using namespace std;

class ASubject
{

public:
    void Attach(IObserver* observer);
    void Detach(IObserver* observer);
    void Notify();
    void Download();

private:
    std::vector<IObserver*> list;

};
