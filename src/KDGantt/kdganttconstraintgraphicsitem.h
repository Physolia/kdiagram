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

#ifndef KDGANTTCONSTRAINTGRAPHICSITEM_H
#define KDGANTTCONSTRAINTGRAPHICSITEM_H

#include <QGraphicsItem>

#include "kdganttconstraint.h"

namespace KDGantt {
    class GraphicsScene;

    class KDGANTT_EXPORT ConstraintGraphicsItem : public QGraphicsItem {
    public:
        enum { Type = UserType + 43 };

        explicit ConstraintGraphicsItem( const Constraint& c,
                                         QGraphicsItem* parent = 0, GraphicsScene* scene = 0 );
        virtual ~ConstraintGraphicsItem();

        /*reimp*/ int type() const;
        /*reimp (non virtual)*/GraphicsScene* scene() const;

        /*reimp*/ QString ganttToolTip() const;

        /*reimp*/ QRectF boundingRect() const;
        /*reimp*/ void paint( QPainter* painter, const QStyleOptionGraphicsItem* option,
                              QWidget* widget = 0 );

        inline const Constraint& constraint() const { return m_constraint; }
        Constraint proxyConstraint() const;

        void setStart( const QPointF& start );
        inline QPointF start() const { return m_start; }
        void setEnd( const QPointF& end );
        inline QPointF end() const { return m_end; }

        void updateItem( const QPointF& start,const QPointF& end );
    private:
        Constraint m_constraint;
        QPointF m_start;
        QPointF m_end;
    };
}

#endif /* KDGANTTCONSTRAINTGRAPHICSITEM_H */

