#include "asubject.h"
#include <algorithm>

using namespace std;

void ASubject::Attach(IObserver *graph)
{
    list.push_back(graph);
}
void ASubject::Detach(IObserver *graph)
{
    list.erase(std::remove(list.begin(), list.end(), graph), list.end());
}



void ASubject::Notify()
{

    for(vector<IObserver*>::const_iterator iter = list.begin(); iter != list.end(); ++iter)
    {
        if(*iter != 0)
        {
            (*iter)->Update();
        }
    }
}
