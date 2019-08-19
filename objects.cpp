#include "objects.h"
#include "sql_db.h"
#include "table_object.h"
#include "table_line.h"
#include "table_text.h"
#include "observer_factory.h"
#include "subject.h"

#include <iostream>

std::vector<TableObject*> Objects::table_objects;
std::map<int,TableText*> Objects::table_texts;
int Objects::size_x;
int Objects::size_y;
Subject* Objects::subjectTime;
Subject* Objects::subjectEvent;

int Objects::load(QWidget *widget)
{
    if (loadParams())
        return 1;
    if (loadTableObjects(widget))
        return 2;
    if (loadText())
        return 3;
    return 0;
}

int Objects::loadParams()
{
    QSqlQuery query;
    query.exec("SET NAMES 'latin1'");
    query.exec("select * from params");
    while (query.next()) {
        QString name = query.value(0).toString();
        if (name=="size_x") {
            size_x = query.value(1).toInt();
        }
        else if (name=="size_y") {
            size_y = query.value(1).toInt();
        }
    }
    return 0;
}

int Objects::loadTableObjects(QWidget *widget)
{
    QSqlQuery query;
    query.exec("select id,type,name,start_x,start_y,width,height,width_line from objects_new order by id");
    while (query.next()) {
        TableObject* to = nullptr;
        int id = query.value(0).toInt();
        QString type = query.value(1).toString();
        if (type=="text") {
            to = new TableText(widget);
            table_texts[id] = static_cast<TableText*>(to);
        }
        else if (type == "line") {
            to = new TableLine(widget);
        }
        else {
            continue;
        }
        table_objects.push_back(to);
        to->setId(id);
        to->setName(query.value(2).toString());
        to->setX(query.value(3).toInt());
        to->setY(query.value(4).toInt());
        to->setWidth(query.value(5).toInt());
        to->setHeight(query.value(6).toInt());
        int widthLine = query.value(7).toInt();
        to->setPen(QPen(QColor(0,0,0),widthLine));
        to->setFrameParam(QPen(QColor(255,0,0),widthLine));
    }
    return 0;
}

int Objects::loadText()
{
    QSqlQuery query;
    query.exec("select id,text,font from text_obj order by id");
    while (query.next()) {
        int id = query.value(0).toInt();
        std::map<int,TableText*>::iterator it = table_texts.find(id);
        if (it != table_texts.end())
        {
            QString fontString = query.value(2).toString();
            try {
                it->second->setFont(parseFont(fontString));
            } catch (const std::exception& e) {
                std::cerr << e.what() << std::endl;
                it->second->setFont(QFont("Sans Serif",10));
            }
            it->second->setText(QString::fromLocal8Bit(query.value(1).toString().toStdString().c_str()));
        }
        else {
            continue;
        }

    }
    return 0;
}

const QFont Objects::parseFont(const QString &fontString)
{
    QString str = fontString;
    int index = str.indexOf("%");
    if (index < 0)
        throw std::runtime_error("Font family not found");
    QString family = str.left(index);
    str.remove(0,index+1);

    index = str.indexOf("%");
    if (index < 0)
        throw std::runtime_error("Font size not found");
    int size = str.left(index).toInt();
    str.remove(0,index+1);

    index = str.indexOf("%");
    if (index < 0)
        throw std::runtime_error("Font weight not found");
    int weight = str.left(index).toInt();
    str.remove(0,index+1);

    index = str.indexOf("%");
    if (index < 0)
        throw std::runtime_error("Font italic flag not found");
    bool isItalic = static_cast<bool>(str.left(index).toInt());

    return QFont(family,size,weight,isItalic);
}

void Objects::initSubjects()
{
    subjectTime  = new Subject();
    subjectEvent = new Subject();
}

void Objects::initObservers()
{
    for (auto it = table_texts.begin(); it != table_texts.end(); ++it)
    {
        ObserverFactory::create(it->second);
    }
}

void Objects::executeEvent(const Event& event)
{
    subjectEvent->notifyObservers(event);
}
