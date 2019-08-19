#include "text_repeats_otc.h"
#include "sql_db.h"
#include <iostream>

TextRepeatsOtc::TextRepeatsOtc(TableText *tableText)
    : Observer(tableText)
{

}

void TextRepeatsOtc::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select ifnull(sum(k_otc*(count-1)),0) from "
                           "(select k_otc,count(*) as count from sl_head_%d where "
                           "idx_p>0 group by nom_p,idx_p,k_vag,k_otc) as sl where sl.count>1")
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
