#include "table_text.h"
#include <qpainter.h>

TableText::TableText(QWidget *widget)
    : TableObject(widget)
{

}

void TableText::paintEvent(QPaintEvent *event)
{
    TableObject::paintEvent(event);
    QPainter painter(this);
    painter.setFont(font);
    painter.drawText(rect(),Qt::AlignCenter,text);
}
