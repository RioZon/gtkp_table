#ifndef TABLEOBJECT_H
#define TABLEOBJECT_H

#include <QWidget>
#include <QPen>


class TableObject : public QWidget
{
public:
    TableObject(QWidget* parent);
    virtual ~TableObject();
    void paintEvent(QPaintEvent *event);

    void setId(const int id) {
        this->id = id;
    }
    void setName(const QString& name) {
        this->name = name;
    }
    const QString& getName() {
        return name;
    }
    void setX(const int x) {
        this->x = x;
    }
    int getX() const {
        return x;
    }
    void setY(const int y) {
        this->y = y;
    }
    int getY() const {
        return y;
    }
    void setWidth(const int width) {
        this->width = width;
    }
    int getWidth() const {
        return width;
    }
    void setHeight(const int height) {
        this->height = height;
    }
    int getHeight() const {
        return height;
    }
    void setFramed(const bool framed) {
        this->isFramed = framed;
    }
    void setPen(const QPen& pen) {
        line_pen = pen;
    }
    void setFrameParam(const QPen& pen, const QBrush& brush = Qt::NoBrush) {
        this->frame_pen = pen;
        this->frame_brush = brush;
    }

protected:
    int id;
    QString name;
    int x;
    int y;
    int width;
    int height;
    bool isFramed;
    QPen line_pen;
    QPen frame_pen;
    QBrush frame_brush;
    QPainter *painter;
};

#endif // TABLEOBJECT_H
