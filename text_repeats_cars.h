#ifndef TEXT_REPEATS_CARS_H
#define TEXT_REPEATS_CARS_H

#include <observer.h>

class TextRepeatsCars : public Observer
{
public:
    TextRepeatsCars(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_REPEATS_CARS_H
