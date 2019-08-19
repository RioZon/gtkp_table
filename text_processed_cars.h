#ifndef TEXT_PROCESSED_CARS_H
#define TEXT_PROCESSED_CARS_H

#include "observer.h"

class TextProcessedCars : public Observer
{
public:
    TextProcessedCars(TableText* tableText);
    void update(const Event &event);
};

#endif // TEXT_PROCESSED_CARS_H
