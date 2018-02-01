#ifndef QDELTAEDIT_H
#define QDELTAEDIT_H

#include <QWidget>

namespace Ui {
class QDeltaEdit;
}

class QDeltaEdit : public QWidget
{
    Q_OBJECT

public:
    explicit QDeltaEdit(QWidget *parent = 0);
    ~QDeltaEdit();
    void setDelta(double value, double target);
private:
    Ui::QDeltaEdit *ui;
    double _value;
    double _target;
};

#endif // QDELTAEDIT_H
