#ifndef OBSERVER_H
#define OBSERVER_H

#include "events.h"
#include "table_text.h"

class Subject;

class Observer
{
public:
    Observer(TableText * tableText);
    void addSubject(Subject* subject);
    void removeSubject(Subject* subject);
    virtual ~Observer();
    virtual void update(const Event& event) = 0;

protected:
    TableText* tableText;
    unsigned int getStartDateTime();

private:
    int base_sm;
};

#endif // OBSERVER_H
