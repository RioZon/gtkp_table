#include "text_speed_thrust_current.h"

TextSpeedThrustCurrent::TextSpeedThrustCurrent(TableText *tableText)
    : Observer(tableText)
{

}

void TextSpeedThrustCurrent::update(const Event &event)
{
    if (event.event != GAC_EV_NAD_SPEED || event.val == 12)
        return;

    tableText->setText(event.val > 0?
                            QString::number(event.val / 32.0 * 3.6, 'f', 1) : "");
}
