/**
 * Copyright (C) 2001-2015 Klaralvdalens Datakonsult AB.  All rights reserved.
 *
 * This file is part of the KD Chart library.
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 2 of
 * the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef KDCHARTPOLARDIAGRAM_H
#define KDCHARTPOLARDIAGRAM_H


#include "KDChartPosition.h"
#include "KDChartAbstractPolarDiagram.h"

QT_BEGIN_NAMESPACE
class QPolygonF;
QT_END_NAMESPACE

namespace KDChart {

/**
  * @brief PolarDiagram defines a common polar diagram
  */
class KDCHART_EXPORT PolarDiagram : public AbstractPolarDiagram
{
    Q_OBJECT

    Q_DISABLE_COPY( PolarDiagram )
    KDCHART_DECLARE_DERIVED_DIAGRAM( PolarDiagram, PolarCoordinatePlane )

public:
    explicit PolarDiagram(
        QWidget* parent = 0, PolarCoordinatePlane* plane = 0 );
    virtual ~PolarDiagram();

protected:
    // Implement AbstractDiagram
    /** \reimpl */
    virtual void paint ( PaintContext* paintContext );

public:
    /** \reimpl */
    virtual void resize ( const QSizeF& area );

    // Implement AbstractPolarDiagram
    /** \reimpl */
    virtual qreal valueTotals () const;
    /** \reimpl */
    virtual qreal numberOfValuesPerDataset() const;
    /** \reimpl */
    virtual qreal numberOfGridRings() const;

    virtual PolarDiagram * clone() const;

    /** \deprecated Use PolarCoordinatePlane::setStartPosition( qreal degrees ) instead. */
    void setZeroDegreePosition( int degrees );
    /** \deprecated Use qreal PolarCoordinatePlane::startPosition instead. */
    int zeroDegreePosition() const;

    void setRotateCircularLabels( bool rotateCircularLabels );
    bool rotateCircularLabels() const;

    /** Close each of the data series by connecting the last point to its
     * respective start point
     */
    void setCloseDatasets( bool closeDatasets );
    bool closeDatasets() const;

    void setShowDelimitersAtPosition( Position position,
                                      bool showDelimiters );
    void setShowLabelsAtPosition( Position position,
                                  bool showLabels );

    bool showDelimitersAtPosition( Position position ) const;

    bool showLabelsAtPosition( Position position ) const;

    virtual void paint ( PaintContext* paintContext,
                         bool calculateListAndReturnScale,
                         qreal& newZoomX, qreal& newZoomY ); // KDChart 3: references -> pointers

protected:
    /** \reimpl */
    virtual const QPair<QPointF, QPointF> calculateDataBoundaries() const;
    void paintEvent ( QPaintEvent* );
    void resizeEvent ( QResizeEvent* );
    virtual void paintPolarMarkers( PaintContext* ctx, const QPolygonF& polygon );

}; // End of class PolarDiagram

}


#endif // KDCHARTPOLARDIAGRAM_H
