#include "text_time.h"
#include "qdatetime.h"

TextTime::TextTime(TableText *tableText)
    : Observer(tableText)
{
    dt = new QDateTime();
    templ = new QString("hh:mm");
}

void TextTime::update(const Event &)
{
    dt->setTime_t(time(0));
    if(tableText->getText() != dt->toString(*templ))
    {
        tableText->setText(dt->toString(*templ));
    }
}

TextTime::~TextTime()
{
    delete templ;
    delete dt;
}
