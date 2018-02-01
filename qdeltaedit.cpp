#include "qdeltaedit.h"
#include "ui_qdeltaedit.h"

QDeltaEdit::QDeltaEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QDeltaEdit), _value(0), _target(0)
{
    ui->setupUi(this);
}

QDeltaEdit::~QDeltaEdit()
{
    delete ui;
}

void QDeltaEdit::setDelta(double value, double target)
{
    _value = value;
    _target = target;
    ui->widget->setDelta(value, target);
    ui->label->setText(QString::number(value, 'f', 3));
}
