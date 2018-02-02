#include "deltavaluepresenter.h"
#include <QPainterPath>
#include <QPen>

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

    QColor deltaColor = Qt::yellow;

    QRect section;
    double sectionSize = _value/_target; // TODO: min-max
    section.setRect( rect.x(), rect.y(), sectionSize*rect.width(), rect.height());
    painter->fillRect( section, deltaColor );

    QPainterPath path;
    path.addRect(rect.x(), rect.y(), rect.width()-1, rect.height()-1);
    QPen pen(Qt::black, 1);
    painter->setPen(pen);
    painter->drawPath(path);

    painter->restore();
}
