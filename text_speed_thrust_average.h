#ifndef TEXT_SPEED_THRUST_AVERAGE_H
#define TEXT_SPEED_THRUST_AVERAGE_H

#include "observer.h"


class TextSpeedThrustAverage :
        public Observer
{
public:
    TextSpeedThrustAverage(TableText *tableText);
    void update(const Event &event);

private:
    bool isDNR; // Флаг роспуска
    unsigned int sumSpeed;  // Сумма всех полученных скоростей с начала роспуска
    unsigned int numberOfMeasures; // Количество полученных измерений

    void nullValues();
};

#endif // TEXT_SPEED_THRUST_AVERAGE_H
