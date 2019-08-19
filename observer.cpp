#include "observer.h"
#include "subject.h"
#include "observer_factory.h"
#include "settings.h"
#include <qdatetime.h>

Observer::Observer(TableText * tableText)
{
    this->tableText = tableText;
}

void Observer::addSubject(Subject* subject)
{
    subject->registerObserver(this);
}

void Observer::removeSubject(Subject* subject)
{
    subject->removeObserver(this);
}

unsigned int Observer::getStartDateTime()
{
    int base_sm = Settings::inst()->get("startTime").toInt();
    QDateTime dt=QDateTime::currentDateTime();
    if(dt.time().hour()>=base_sm+12 || dt.time().hour()<base_sm) //ночная смена
    {
        if(dt.time().hour()<base_sm)
            dt=dt.addSecs(-3600*12);
        dt.setTime(QTime(base_sm+12,0));
    }
    else // дневная смена
    {
        dt.setTime(QTime(base_sm,0));
    }
    return dt.toTime_t();
}

Observer::~Observer()
{

}
