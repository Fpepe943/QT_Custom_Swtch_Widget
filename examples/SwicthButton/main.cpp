#include <QApplication>
#include "qcswitchwidget.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToggleButton w;
    w.setStylesheet("../../../examples/SwicthButton/toggle_on.png", "../../../examples/SwicthButton/toggle_off.png");
    w.show();
    return a.exec();
}
