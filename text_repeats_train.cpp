#include "text_repeats_train.h"
#include "sql_db.h"
#include <iostream>

TextRepeatsTrain::TextRepeatsTrain(TableText *tableText)
    : Observer(tableText)
{

}

void TextRepeatsTrain::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select ifnull(sum(count)-count(*),0) from "
                           "(select count(*) as count from sl_head_%d where idx_p>0 "
                           "group by nom_p,idx_p,k_vag,k_otc) "
                           "as count where count.count>1").arg(getStartDateTime()));
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
