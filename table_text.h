#ifndef TABLE_TEXT_H
#define TABLE_TEXT_H

#include "table_object.h"

class TableText : public TableObject
{
public:
    TableText(QWidget* widget);
    void setFont(const QFont & font) {
        this->font = font;
    }
    void setText(const QString& text) {
        this->text = text;
    }
    const QString& getText() const {
        return text;
    }

protected:
    void paintEvent(QPaintEvent *event);
    QFont font;
    QString text;
};

#endif // TABLE_TEXT_H
