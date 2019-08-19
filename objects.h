#ifndef OBJECTS_H
#define OBJECTS_H

#include <vector>
#include <map>
#include <QWidget>


class TableObject;
class TableText;
class Subject;
class Observer;
class Event;

class Objects
{
public:
    static int load(QWidget* widget);
    static int loadParams();
    static int loadTableObjects(QWidget *widget);
    static int loadText();
    static int sizeX() {return size_x;}
    static int sizeY() {return size_y;}
    static Subject* getSubjectTime() {return subjectTime;}
    static Subject* getSubjectEvent() {return subjectEvent;}

private:
    static std::vector<TableObject*> table_objects;
    static std::map<int,TableText*> table_texts;
    static int size_x;
    static int size_y;

    static Subject* subjectTime;
    static Subject* subjectEvent;

    static const QFont parseFont(const QString& fontString);
    static void initSubjects();
    static void initObservers();
    static void executeEvent(const Event& event);

};

#endif // OBJECTS_H
