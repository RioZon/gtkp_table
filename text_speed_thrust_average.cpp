#include "text_speed_thrust_average.h"

TextSpeedThrustAverage::TextSpeedThrustAverage(TableText *tableText)
    : Observer(tableText)
{
    isDNR = false;
    sumSpeed = 0;
    numberOfMeasures = 0;
}

void TextSpeedThrustAverage::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        isDNR = event.val;
        if (!isDNR)
        {
            nullValues();
        }
    }

    if (event.event != GAC_EV_NAD_SPEED || !isDNR)
        return;

    sumSpeed += event.val;
    ++numberOfMeasures;

    tableText->setText(QString::number(sumSpeed/(numberOfMeasures*32.0) * 3.6, 'f', 1));
}

void TextSpeedThrustAverage::nullValues()
{
    sumSpeed = 0;
    numberOfMeasures = 0;
}
