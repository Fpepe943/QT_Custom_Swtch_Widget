#include <QApplication>
#include <qcswitchwidget.h>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    ToggleButton w;
    w.setStylesheet("../../../examples/OnOffButton/power_on.png", "../../../examples/OnOffButton/power_off.png");
    w.show();
    return a.exec();
}
