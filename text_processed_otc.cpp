#include "text_processed_otc.h"
#include "sql_db.h"
#include <iostream>

TextProcessedOtc::TextProcessedOtc(TableText *tableText)
    : Observer(tableText)
{

}

void TextProcessedOtc::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select count(*) from iu_head_%d").arg(getStartDateTime()));
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
