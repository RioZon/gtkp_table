#include "observer_factory.h"
#include "objects.h"
#include "table_text.h"
#include "observer.h"
#include "text_time.h"
#include "text_time_start_rosp.h"
#include "text_speed_thrust_current.h"
#include "text_speed_thrust_average.h"
#include "text_num_rosp.h"
#include "text_num_train.h"
#include "text_rasform_trains.h"
#include "text_rasform_cars.h"
#include "text_processed_trains.h"
#include "text_processed_cars.h"
#include "text_processed_otc.h"
#include "text_repeats_train.h"
#include "text_repeats_otc.h"
#include "text_repeats_cars.h"
#include "text_cycle.h"
#include "text_interval.h"


Observer *ObserverFactory::create(TableText *tableText)
{
    Observer *observer = 0;
    if (!tableText)
        return observer;

    const QString name = tableText->getName();

    //---------------------------------------
    if (name == "time")
    {
        observer = new TextTime(tableText);
        observer->addSubject(Objects::getSubjectTime());
    }
    else if (name == "time_start_rosp")
    {
        observer = new TextTimeStartRosp(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "speed_thrust_current")
    {
        observer = new TextSpeedThrustCurrent(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "speed_thrust_average")
    {
        observer = new TextSpeedThrustAverage(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "num_rosp")
    {
        observer = new TextNumRosp(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "num_train")
    {
        observer = new TextNumTrain(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "rasform_trains")
    {
        observer = new TextRasformTrains(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "rasform_cars")
    {
        observer = new TextRasformCars(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "processed_trains")
    {
        observer = new TextProcessedTrains(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "processed_otc")
    {
        observer = new TextProcessedOtc(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name == "processed_cars")
    {
        observer = new TextProcessedCars(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name=="repeats_trains")
    {
        observer = new TextRepeatsTrain(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name=="repeats_otc")
    {
        observer = new TextRepeatsOtc(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name=="repeats_cars")
    {
        observer = new TextRepeatsCars(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name=="cycle")
    {
        observer = new TextCycle(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }
    else if (name=="interval")
    {
        observer = new TextInterval(tableText);
        observer->addSubject(Objects::getSubjectEvent());
    }

    // your implementation here...
    //---------------------------------------
    return observer;
}
