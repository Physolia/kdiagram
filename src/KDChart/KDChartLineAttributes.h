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

#ifndef KDCHARTLINEATTRIBUTES_H
#define KDCHARTLINEATTRIBUTES_H

#include <QMetaType>
#include "KDChartGlobal.h"

namespace KDChart {

/**
  * @brief Set of attributes for changing the appearance of line charts
  */
class KDCHART_EXPORT LineAttributes
{
public:
    /**
      \brief MissingValuesPolicy specifies how a missing value will be shown in a line diagram.

      Missing value is assumed if the data cell contains a QVariant that can not be
      interpreted as a qreal, or if the data cell is hidden while its dataset is not hidden.

      \li \c MissingValuesAreBridged the default: No markers will be shown for missing values
      but the line will be bridged if there is at least one valid cell before and after
      the missing value(s), otherwise the segment will be hidden.
      \li \c MissingValuesHideSegments Line segments starting with a missing value will
      not be shown, and no markers will be shown for missing values, so this will look like
      a piece of the line is missing.
      \li \c MissingValuesShownAsZero Missing value(s) will be treated like normal zero values,
      and markers will shown for them too, so there will be no visible difference between a
      zero value and a missing value.
      \li \c MissingValuesPolicyIgnored (internal value, do not use)

      */
    enum MissingValuesPolicy {
        MissingValuesAreBridged,
        MissingValuesHideSegments,
        MissingValuesShownAsZero,
        MissingValuesPolicyIgnored };

    LineAttributes();
    LineAttributes( const LineAttributes& );
    LineAttributes &operator= ( const LineAttributes& );

    ~LineAttributes();

    /* line chart and area chart - all types */
    void setMissingValuesPolicy( MissingValuesPolicy policy );
    MissingValuesPolicy missingValuesPolicy() const;

    /* area chart - all types */
    /**
     * Sets the lower or upper (depending on the displayed value being positive or
     * negative, resp.) bounding line (i.e., the dataset with the line data). The area
     * is then drawn between this line and the line of the specified dataset.
     * Pass -1 to draw the area between this line and the zero line.
     */
    void setAreaBoundingDataset( int dataset );
    int areaBoundingDataset() const;

    void setDisplayArea( bool display );
    bool displayArea() const;
    /*allows viewing the covered areas*/
    void setTransparency( uint alpha );
    uint transparency() const;

    bool operator==( const LineAttributes& ) const;
    inline bool operator!=( const LineAttributes& other ) const { return !operator==(other); }

private:
    KDCHART_DECLARE_PRIVATE_BASE_VALUE( LineAttributes )
}; // End of class LineAttributes

}

#if !defined(QT_NO_DEBUG_STREAM)
KDCHART_EXPORT QDebug operator<<(QDebug, const KDChart::LineAttributes& );
#endif /* QT_NO_DEBUG_STREAM */

KDCHART_DECLARE_SWAP_SPECIALISATION( KDChart::LineAttributes )

QT_BEGIN_NAMESPACE
Q_DECLARE_TYPEINFO( KDChart::LineAttributes, Q_MOVABLE_TYPE );
QT_END_NAMESPACE

Q_DECLARE_METATYPE( KDChart::LineAttributes )

#endif // KDCHARTLINEATTRIBUTES_H
