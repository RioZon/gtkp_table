#include "text_num_train.h"
#include "sql_db.h"
#include "events.h"
#include "iostream"

TextNumTrain::TextNumTrain(TableText *tableText)
    : Observer(tableText)
{

}

void TextNumTrain::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec("select telo_mes from merge_iu_kom where tip_mes=1 order by time desc limit 1");
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
