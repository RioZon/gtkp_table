#include "table_object.h"
#include <qpainter.h>

TableObject::TableObject(QWidget *parent)
    : QWidget(parent)
{
    id = 0;
    name="";
    x = 0;
    y = 0;
    width = 0;
    height = 0;
    isFramed = false;
    line_pen = Qt::NoPen;
    frame_pen = Qt::NoPen;
    frame_brush = Qt::NoBrush;
}

void TableObject::paintEvent(QPaintEvent *event)
{
    Q_UNUSED(event);
    setGeometry(x,y,width,height);
    QPainter painter(this);
    painter.setPen(frame_pen);
    painter.setBrush(frame_brush);
    if (isFramed) {
        painter.drawRect(0,0,width,height);
    }

}

TableObject::~TableObject() {}
