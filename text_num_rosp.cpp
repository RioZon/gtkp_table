#include "text_num_rosp.h"
#include "sql_db.h"
#include <iostream>

TextNumRosp::TextNumRosp(TableText *tableText)
    : Observer(tableText)
{

}

void TextNumRosp::update(const Event &event)
{
    if (event.event == GAC_EV_DNR)
    {
        QSqlQuery query;
        query.exec("select max(nom_prot) from merge_iu_kom");
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
