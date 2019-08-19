#include "text_rasform_cars.h"
#include "sql_db.h"
#include <iostream>

TextRasformCars::TextRasformCars(TableText *tableText)
    : Observer(tableText)
{

}

void TextRasformCars::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec(QString("select count(*) from sl_inf_%d").arg(getStartDateTime()));
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
