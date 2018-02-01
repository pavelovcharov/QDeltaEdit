#ifndef DELTAVALUEPRESENTER_H
#define DELTAVALUEPRESENTER_H

#include <QWidget>
#include <QPainter>
#include <QColor>

class DeltaValuePresenter : public QWidget
{
    double _value;
    double _target;
public:
    DeltaValuePresenter(QWidget* parent = 0);
    void setDelta(double value, double target);
protected:
    virtual void paintEvent( QPaintEvent * );

    void drawColorBar( QPainter *painter, const QRect &rect ) const;
};


#endif // DELTAVALUEPRESENTER_H


