#include "subject.h"
#include "observer.h"

#include <algorithm>

void Subject::registerObserver(Observer *observer)
{
    if (!observer)
        return;
    if (std::find(observers.begin(),observers.end(),observer) != observers.end())
        return;

    observers.push_back(observer);
}

void Subject::removeObserver(Observer *observer)
{
    if (!observer)
        return;

    observers.remove(observer);
}

void Subject::notifyObservers(const Event &event)
{
    for (auto it = observers.begin(); it != observers.end(); ++it)
    {
        (*it)->update(event);
    }
}
