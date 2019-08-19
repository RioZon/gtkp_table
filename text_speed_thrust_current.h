#ifndef TEXT_SPEED_NADVIG_CURRENT_H
#define TEXT_SPEED_NADVIG_CURRENT_H

#include "observer.h"

class TextSpeedThrustCurrent : public Observer
{
public:
    TextSpeedThrustCurrent(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_SPEED_NADVIG_CURRENT_H
