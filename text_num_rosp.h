#ifndef TEXT_NUM_ROSP_H
#define TEXT_NUM_ROSP_H

#include "observer.h"

class TextNumRosp : public Observer
{
public:
    TextNumRosp(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_NUM_ROSP_H
