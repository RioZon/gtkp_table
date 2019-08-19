#include "text_processed_trains.h"
#include "sql_db.h"
#include <iostream>

TextProcessedTrains::TextProcessedTrains(TableText *tableText)
    : Observer(tableText)
{

}

void TextProcessedTrains::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select count(*) from (select count(*) from iu_head_%d group by time) as result")
                   .arg(getStartDateTime()));
        while (query.next()) {
            try {
                tableText->setText(query.value(0).toString());
            }
            catch (const std::exception &ex) {
                std::cerr << ex.what() << std::endl;
                return;
            }
        }
    }
}
