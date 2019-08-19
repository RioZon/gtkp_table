#include "text_cycle.h"
#include "sql_db.h"
#include <iostream>
#include <math.h>

TextCycle::TextCycle(TableText *tableText)
    : Observer(tableText)
{

}

void TextCycle::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        double sum = 0;
        int prev_value = -1;
        unsigned int count = 0;
        QSqlQuery query;
        query.exec(QString("select time from iu_kom_%d where tip_mes=1").arg(getStartDateTime()));
        while (query.next())
        {
            if (prev_value == -1)
            {
                prev_value = query.value(0).toInt();
                continue;
            }
            sum += query.value(0).toInt() - prev_value;
            prev_value = query.value(0).toInt();
            ++count;
        }
        double avg = sum / count;
        avg /= 60;

        try {
            tableText->setText(QString::number(round(avg)));
        }
        catch (const std::exception &ex) {
            std::cerr << ex.what() << std::endl;
            return;
        }
    }
}
