#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>
class Observer;
class Event;

class Subject
{
public:
    void registerObserver(Observer *observer);
    void removeObserver(Observer *observer);
    void notifyObservers(const Event &event);

private:
    std::list<Observer*> observers;
};

#endif // SUBJECT_H
