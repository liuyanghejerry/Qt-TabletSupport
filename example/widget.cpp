#include "widget.h"
#include <QTabletEvent>
#include <QMouseEvent>
#include <QDebug>

#include "../tabletsupport.h"

Widget::Widget(QWidget *parent) :
    QWidget(parent),
    tabletSupport_(new TabletSupport(this)),
    pic(new QPixmap(1366, 768))
{
    pic->fill(Qt::white);
    drawing = false;
    tabletSupport_->start();
}

Widget::~Widget()
{
    delete tabletSupport_;
    delete pic;
}

QSize Widget::sizeHint() const
{
    return QSize(720,480);
}

void Widget::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.drawLine(0,0,100,100);
    painter.drawPixmap(0,0,*pic);
}

void Widget::tabletEvent(QTabletEvent *ev)
{
    QPainter painter(pic);
    painter.setRenderHint(QPainter::Antialiasing);
    QPen pen;
    int maxWidth = 5;
    pen.setWidth(maxWidth);
    pen.setCapStyle(Qt::RoundCap);
    pen.setJoinStyle(Qt::RoundJoin);
    pen.setColor(Qt::blue);
    painter.setPen(pen);
    switch(ev->type()){
    case QEvent::TabletPress:
        if(!drawing){
            lastPoint = ev->pos();
            drawing = true;
            pen.setWidthF(maxWidth * ev->pressure());
            painter.setPen(pen);
            painter.drawPoint(ev->pos());
        }
        break;
    case QEvent::TabletMove:
        if(drawing && lastPoint != ev->pos()){
            pen.setWidthF(maxWidth * ev->pressure());
            painter.setPen(pen);
            painter.drawLine(lastPoint, ev->pos());
            lastPoint = ev->pos();
        }
        break;
    case QEvent::TabletRelease:
        if(drawing){
            drawing = false;
        }
        break;
    default:
        break;
    }
    ev->accept();
    update();
}
