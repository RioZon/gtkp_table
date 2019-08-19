#ifndef OBSERVER_FACTORY_H
#define OBSERVER_FACTORY_H

class Observer;
class TableText;

class ObserverFactory
{
public:
    static Observer* create(TableText *tableText);

private:
    ObserverFactory() {}
};

#endif // OBSERVER_FACTORY_H
