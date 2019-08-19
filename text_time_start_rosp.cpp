#include "text_time_start_rosp.h"
#include "sql_db.h"
#include <iostream>

TextTimeStartRosp::TextTimeStartRosp(TableText *tableText)
    : Observer(tableText)
{
}

void TextTimeStartRosp::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec("select time from merge_iu_kom where tip_mes=1 order by time desc limit 1");
        while (query.next()) {
            try {
                time_t unixtime = query.value(0).toInt();
                QDateTime qdt;
                qdt.setTime_t(unixtime);
                tableText->setText(qdt.toString("hh:mm"));
            }
            catch (const std::exception &ex) {
                std::cerr << ex.what() << std::endl;
                return;
            }
        }
    }
}

TextTimeStartRosp::~TextTimeStartRosp()
{
}
