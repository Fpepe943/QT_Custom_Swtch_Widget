#include "switchbutton.h"

#include <QApplication>
#include <QHBoxLayout>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QWidget *widget = new QWidget;
    QHBoxLayout layout;
    widget->setLayout(&layout);
    widget->setMinimumSize(100,50);
    SwitchButton* sbtn = new SwitchButton(widget, SwitchButton::Style::ONOFF); // Default style is Style::ONOFF
    bool current = sbtn->value();
    sbtn->setValue(!current);
    layout.addWidget(sbtn);
    widget->show();
    return a.exec();

}

