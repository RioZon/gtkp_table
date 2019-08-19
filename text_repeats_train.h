#ifndef TEXT_REPEATS_TRAIN_H
#define TEXT_REPEATS_TRAIN_H

#include "observer.h"

class TextRepeatsTrain : public Observer
{
public:
    TextRepeatsTrain(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_REPEATS_TRAIN_H
