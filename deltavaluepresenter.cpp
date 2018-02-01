#include "deltavaluepresenter.h"
DeltaValuePresenter::DeltaValuePresenter(QWidget* parent) : QWidget(parent),
    _value(0), _target(0){
}
void DeltaValuePresenter::setDelta(double value, double target) {
    _value = value;
    _target = target;
}

void DeltaValuePresenter::paintEvent( QPaintEvent * )
{
    QPainter painter( this );
    drawColorBar( &painter, rect() );
}

void DeltaValuePresenter::drawColorBar( QPainter *painter, const QRect &rect ) const
{

    painter->save();
    painter->setClipRect( rect );
    painter->setClipping( true );

    QColor d_dark = Qt::black;

//    painter->fillRect( rect, d_dark );


    QColor deltaColor = Qt::yellow;

    QRect section;

    double v = _value;
    double t = _target;
    double s = v/t;

    double sectionSize = _value/_target; // TODO: min-max
    section.setRect( rect.x(), rect.y(), sectionSize*rect.width(), rect.height());
    painter->fillRect( section, deltaColor );
    painter->restore();
}
