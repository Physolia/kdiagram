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

#ifndef KDGANTTTREEVIEWROWCONTROLLER_P_H
#define KDGANTTTREEVIEWROWCONTROLLER_P_H

#include "kdganttabstractrowcontroller.h"

#include <QTreeView>

QT_BEGIN_NAMESPACE
class QAbstractProxyModel;
QT_END_NAMESPACE

namespace KDGantt {
    class TreeViewRowController::Private {
    public:
        class HackTreeView : public QTreeView {
        public:
            using QTreeView::verticalOffset;
#if QT_VERSION >= 0x040300
            using QTreeView::rowHeight;
#else
            using QTreeView::indexRowSizeHint;
#endif
        };
        HackTreeView* treeview;
        QAbstractProxyModel* proxy;
    };
}

#endif /* KDGANTTTREEVIEWROWCONTROLLER_P_H */

