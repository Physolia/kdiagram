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

#ifndef ZOOMWIDGET_H
#define ZOOMWIDGET_H

#include <KChartWidget>

class ZoomWidget : public KChart::Widget
{
    Q_OBJECT

public:
    explicit ZoomWidget( QWidget* parent );

protected:
    QPointF findNewZoomCenter( const QPoint & pos );
    void mousePressEvent( QMouseEvent * e ) Q_DECL_OVERRIDE;
    void wheelEvent( QWheelEvent* e ) Q_DECL_OVERRIDE;
    void keyPressEvent( QKeyEvent* e ) Q_DECL_OVERRIDE;
};


#endif /* ZOOMWIDGET_H */

