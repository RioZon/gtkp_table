#include "text_repeats_cars.h"
#include "sql_db.h"
#include <iostream>

TextRepeatsCars::TextRepeatsCars(TableText *tableText)
    : Observer(tableText)
{

}

void TextRepeatsCars::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select ifnull(sum(k_vag*(count-1)),0) from "
                           "(select k_vag,count(*) as count from sl_head_%d "
                           "where idx_p>0 group by nom_p,idx_p,k_vag,k_otc) as sl where sl.count>1")
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
