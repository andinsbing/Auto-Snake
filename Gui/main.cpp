#include "widget.h"
#include <QApplication>
#include"console_main.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
//    console_main();
    return a.exec();
}
