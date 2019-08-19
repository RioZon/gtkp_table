#ifndef TEXT_PROCESSED_OTC_H
#define TEXT_PROCESSED_OTC_H

#include "observer.h"

class TextProcessedOtc : public Observer
{
public:
    TextProcessedOtc(TableText* tableText);
    void update(const Event &event);
};

#endif // TEXT_PROCESSED_OTC_H
