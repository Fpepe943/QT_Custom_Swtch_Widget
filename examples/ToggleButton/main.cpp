#include "togglebutton.h"
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *widget = new QWidget;
    QHBoxLayout layout;
    widget->setLayout(&layout);
    ToggleButton *toggleButton1 = new ToggleButton(10, 8);
    layout.addWidget(toggleButton1);
    widget->show();
    return a.exec();
}
