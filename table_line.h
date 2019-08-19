#ifndef TABLE_LINE_H
#define TABLE_LINE_H

#include "table_object.h"

class TableLine : public TableObject
{
public:
    TableLine(QWidget* parent);

    // QWidget interface
protected:
    void paintEvent(QPaintEvent *event);
};

#endif // TABLE_LINE_H
