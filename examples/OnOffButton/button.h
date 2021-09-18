#ifndef BUTTON_H
#define BUTTON_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class Button; }
QT_END_NAMESPACE

class Button : public QWidget
{
    Q_OBJECT

public:
    Button(QWidget *parent = nullptr);
    ~Button();
    void setTextLabel(const QString& text);
signals:
    void checked(bool  check);

private:
    Ui::Button *ui;
};
#endif // BUTTON_H
