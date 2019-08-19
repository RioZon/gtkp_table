#include "text_processed_cars.h"
#include "sql_db.h"
#include <iostream>

TextProcessedCars::TextProcessedCars(TableText *tableText)
    : Observer(tableText)
{

}

void TextProcessedCars::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select count(*) from iu_inf_%d").arg(getStartDateTime()));
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
