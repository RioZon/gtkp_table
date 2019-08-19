#include "widget.h"
#include "objects.h"
#include <QPainter>
#include <qlabel.h>
#include "table_object.h"
#include "sql_db.h"

MainWidget::MainWidget(QWidget *parent)
    : QWidget(parent)
{
    Objects::load(this);
    resize(Objects::sizeX(),Objects::sizeY());
    SQL_DB::connectData();
}

MainWidget::~MainWidget()
{

}
