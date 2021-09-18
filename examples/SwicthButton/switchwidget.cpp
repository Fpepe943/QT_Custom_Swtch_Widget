#include "switchwidget.h"
#include "ui_switchwidget.h"
#include <qfile.h>
#include <iostream>
SwitchWidget::SwitchWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::SwitchWidget)
{
    ui->setupUi(this);

    QFile file(":/qss/SwitchWidget.qss");
    file.open(QFile::ReadOnly);
    QString styleSheet = QLatin1String(file.readAll());
    setStyleSheet(styleSheet);
    QObject::connect(ui->switchPushButton, &QPushButton::toggled, this, &SwitchWidget::checked);

}

SwitchWidget::~SwitchWidget()
{
    delete ui;
}

void SwitchWidget::setTextLabel(const QString& text)
{
    ui->switchLabel->setText(text);
}

