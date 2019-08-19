#ifndef TEXT_NUM_TRAIN_H
#define TEXT_NUM_TRAIN_H

#include "observer.h"

class TextNumTrain : public Observer
{
public:
    TextNumTrain(TableText *tableText);
    void update(const Event &event);
};

#endif // TEXT_NUM_TRAIN_H
