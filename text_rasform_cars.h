#ifndef TEXT_RASFORM_CARS_H
#define TEXT_RASFORM_CARS_H

#include <observer.h>

class TextRasformCars : public Observer
{
public:
    TextRasformCars(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_RASFORM_CARS_H
