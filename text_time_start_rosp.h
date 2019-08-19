#ifndef TEXT_TIME_START_ROSP_H
#define TEXT_TIME_START_ROSP_H

#include "observer.h"


class TextTimeStartRosp
        :public Observer
{
public:
    TextTimeStartRosp(TableText* tableText);
    void update(const Event &event);
    ~TextTimeStartRosp();
};

#endif // TEXT_TIME_START_ROSP_H
