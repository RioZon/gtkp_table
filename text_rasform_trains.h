#ifndef TEXT_RASFORM_TRAINS_H
#define TEXT_RASFORM_TRAINS_H

#include <observer.h>

class TextRasformTrains : public Observer
{
public:
    TextRasformTrains(TableText * tableText);
    void update(const Event &event);
};

#endif // TEXT_RASFORM_TRAINS_H
