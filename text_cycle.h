#ifndef TEXT_CYCLE_H
#define TEXT_CYCLE_H

#include "observer.h"

class TextCycle : public Observer
{
public:
    TextCycle(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_CYCLE_H
