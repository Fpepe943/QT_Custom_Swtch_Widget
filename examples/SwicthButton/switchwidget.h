#ifndef SWITCHWIDGET_H
#define SWITCHWIDGET_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class SwitchWidget; }
QT_END_NAMESPACE

class SwitchWidget : public QWidget
{
    Q_OBJECT

public:
    SwitchWidget(QWidget *parent = nullptr);
    ~SwitchWidget();
    void setTextLabel(const QString& text);
signals:
    void checked(bool  check);

private:
    Ui::SwitchWidget *ui;
};
#endif // SWITCHWIDGET_H
