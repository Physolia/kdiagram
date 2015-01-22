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

#ifndef KDCHARTABSTRACTTHREEDATTRIBUTES_P_H
#define KDCHARTABSTRACTTHREEDATTRIBUTES_P_H

//
//  W A R N I N G
//  -------------
//
// This file is not part of the KD Chart API.  It exists purely as an
// implementation detail.  This header file may change from version to
// version without notice, or even be removed.
//
// We mean it.
//

#include <KDChartAbstractThreeDAttributes.h>

#include <KDABLibFakes>


namespace KDChart {

/**
 * \internal
 */
class AbstractThreeDAttributes::Private
{
    friend class AbstractThreeDAttributes;
public:
    Private();

private:
    bool enabled;
// FIXME: What is this needed for? height is not referenced anywhere.
//    int height;
    qreal depth;
    bool threeDBrushEnabled;
};

inline AbstractThreeDAttributes::AbstractThreeDAttributes( Private * p ) : _d( p ) { init(); }

}

#endif // KDCHARTABSTRACTTHREEDATTRIBUTES_P_H
