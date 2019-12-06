/*
 * Copyright (C) 2001-2015 Klaralvdalens Datakonsult AB.  All rights reserved.
 *
 * This file is part of the KGantt library.
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
 * along with this program.  If not, see <https://www.gnu.org/licenses/>.
 */

#ifndef KGANTTLEGEND_H
#define KGANTTLEGEND_H

#include <QAbstractItemView>

#include "kganttglobal.h"
#include "kganttstyleoptionganttitem.h"

namespace KGantt 
{
    class KGANTT_EXPORT Legend : public QAbstractItemView
    {
        Q_OBJECT
        KGANTT_DECLARE_PRIVATE_BASE_POLYMORPHIC( Legend )
    public:
        explicit Legend( QWidget* parent = nullptr );
        virtual ~Legend();

        /*reimp*/ QModelIndex indexAt( const QPoint& point ) const override;
        /*reimp*/ QRect visualRect( const QModelIndex& index ) const override;

        /*reimp*/ void scrollTo( const QModelIndex&, ScrollHint = EnsureVisible ) override {}

        /*reimp*/ QSize sizeHint() const override;
        /*reimp*/ QSize minimumSizeHint() const override;

        /*reimp*/ void setModel( QAbstractItemModel* model ) override;

    protected:
        virtual QRect drawItem( QPainter* painter, const QModelIndex& index, const QPoint& pos = QPoint() ) const;
        virtual QSize measureItem( const QModelIndex& index, bool recursive = true ) const;
        virtual StyleOptionGanttItem getStyleOption( const QModelIndex& index ) const;

        /*reimp*/ void paintEvent( QPaintEvent* event ) override;

        /*reimp*/ int horizontalOffset() const override { return 0; }
        /*reimp*/ bool isIndexHidden( const QModelIndex& ) const override { return false; }
        /*reimp*/ QModelIndex moveCursor( CursorAction, Qt::KeyboardModifiers ) override { return QModelIndex(); }
        /*reimp*/ void setSelection( const QRect&, QItemSelectionModel::SelectionFlags ) override {}
        /*reimp*/ int verticalOffset() const override { return 0; }
        /*reimp*/ QRegion visualRegionForSelection( const QItemSelection& ) const override { return QRegion(); }

    protected Q_SLOTS:
        virtual void modelDataChanged();
    };
}

#endif
