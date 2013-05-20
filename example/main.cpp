#include "widget.h"
#include <QApplication>
#include <QScrollArea>


int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QScrollArea area;
    Widget w;
//    w.show();
    area.setWidget(&w);
    area.setBackgroundRole(QPalette::Dark);
    area.show();
    area.ensureWidgetVisible(&w);
    
    return a.exec();
}
