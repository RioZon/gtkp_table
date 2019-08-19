#ifndef TEXT_INTERVAL_H
#define TEXT_INTERVAL_H

#include "observer.h"


class TextInterval : public Observer
{
public:
    TextInterval(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_INTERVAL_H
