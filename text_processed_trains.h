#ifndef PROCESSED_TRAINS_H
#define PROCESSED_TRAINS_H

#include "observer.h"

class TextProcessedTrains : public Observer
{
public:
    TextProcessedTrains(TableText* tableText);
    void update(const Event &event);
};

#endif // PROCESSED_TRAINS_H
