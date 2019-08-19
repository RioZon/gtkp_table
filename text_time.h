#ifndef TEXT_TIME_OBSERVER_H
#define TEXT_TIME_OBSERVER_H

#include "observer.h"

class TextTime : public Observer
{
public:
    TextTime(TableText * tableText);
    void update(const Event &);
    ~TextTime();

private:
    QDateTime* dt;
    QString* templ;
};

#endif // TEXT_TIME_OBSERVER_H
