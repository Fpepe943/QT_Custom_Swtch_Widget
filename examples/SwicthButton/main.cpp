#include "switchwidget.h"

#include <QApplication>

#include <iostream>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SwitchWidget w;
    w.setTextLabel("Cabin light");



    w.show();
    return a.exec();
}
