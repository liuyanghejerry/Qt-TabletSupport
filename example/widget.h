#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPainter>
#include <QPen>
#include <QBrush>

class TabletSupport;

class Widget : public QWidget
{
    Q_OBJECT
    
public:
    explicit Widget(QWidget *parent = 0);
    ~Widget();
    QSize sizeHint() const;
protected:
    void paintEvent(QPaintEvent *ev);
    void tabletEvent(QTabletEvent *ev);
private:
    TabletSupport *tabletSupport_;
    QPixmap *pic;
    bool drawing = false;
    QPoint lastPoint;
};

#endif // WIDGET_H
