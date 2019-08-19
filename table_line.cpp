#include "table_line.h"
#include <qpainter.h>
#include <iostream>

TableLine::TableLine(QWidget* parent)
    : TableObject(parent)
{

}

void TableLine::paintEvent(QPaintEvent *event)
{
    TableObject::paintEvent(event);
    int x0,x1,y0,y1;
    if (width > height) { //horizontal
        x0 = 0;
        x1 = width;
        y0 = y1 = height/2;
    }
    else {
        x0 = x1 = width/2;
        y0 = 0;
        y1 = height;
    }
    QPainter painter(this);
    painter.setPen(line_pen);
    painter.drawLine(x0,y0,x1,y1);
}
