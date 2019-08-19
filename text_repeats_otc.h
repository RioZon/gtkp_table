#ifndef TEXT_REPEATS_OTC_H
#define TEXT_REPEATS_OTC_H


#include "observer.h"

class TextRepeatsOtc : public Observer
{
public:
    TextRepeatsOtc(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_REPEATS_OTC_H
