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

#ifndef KDCHARTCHART_P_H
#define KDCHARTCHART_P_H

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

#include <QObject>
#include <QHBoxLayout>
#include <QVBoxLayout>

#include "KDChartChart.h"
#include "KDChartAbstractArea.h"
#include "KDChartTextArea.h"
#include "KDChartFrameAttributes.h"
#include "KDChartBackgroundAttributes.h"
#include "KDChartLayoutItems.h"

#include <KDABLibFakes>


namespace KDChart {

class AbstractAreaWidget;
class CartesianAxis;

/*
  struct PlaneInfo can't be declared inside Chart::Private, otherwise MSVC.net says:
  qhash.h(195) : error C2248: 'KDChart::Chart::Private' : cannot access protected class declared in class 'KDChart::Chart'
  KDChartChart_p.h(58) : see declaration of 'KDChart::Chart::Private'
  KDChartChart.h(61) : see declaration of 'KDChart::Chart'
  KDChartChart.cpp(262) : see reference to class template instantiation 'QHash<Key,T>' being compiled, with
            Key=KDChart::AbstractCoordinatePlane *,
            T=KDChart::Chart::Private::PlaneInfo
*/
/**
 * \internal
 */
struct PlaneInfo {
    PlaneInfo()
        : referencePlane( 0 ),
          horizontalOffset( 1 ),
          verticalOffset( 1 ),
          gridLayout( 0 ),
          topAxesLayout( 0 ),
          bottomAxesLayout( 0 ),
          leftAxesLayout( 0 ),
          rightAxesLayout( 0 )
    {}
    AbstractCoordinatePlane *referencePlane;
    int horizontalOffset;
    int verticalOffset;
    QGridLayout* gridLayout;
    QVBoxLayout* topAxesLayout;
    QVBoxLayout* bottomAxesLayout;
    QHBoxLayout* leftAxesLayout;
    QHBoxLayout* rightAxesLayout;
};

struct LayoutGraphNode
{
    LayoutGraphNode()
        : diagramPlane( 0 )
        , leftSuccesor( 0 )
        , bottomSuccesor( 0 )
        , sharedSuccesor( 0 )
        , gridLayout( 0 )
        , topAxesLayout( false )
        , bottomAxesLayout( false )
        , leftAxesLayout( false )
        , rightAxesLayout( false )
        , priority( -1 )
    {}
    AbstractCoordinatePlane* diagramPlane;
    LayoutGraphNode* leftSuccesor;
    LayoutGraphNode* bottomSuccesor;
    LayoutGraphNode* sharedSuccesor;
    QGridLayout* gridLayout;
    bool topAxesLayout;
    bool bottomAxesLayout;
    bool leftAxesLayout;
    bool rightAxesLayout;
    int priority;
    bool operator<( const LayoutGraphNode &other ) const
    {
        return priority < other.priority;
    }
};


/**
 * \internal
 */
class Chart::Private : public QObject
{
    Q_OBJECT
    public:
        Chart* chart;

        enum AxisType { Abscissa, Ordinate };
        bool useNewLayoutSystem;
        CoordinatePlaneList coordinatePlanes;
        HeaderFooterList headerFooters;
        LegendList legends;

        QHBoxLayout* layout;
        QVBoxLayout* vLayout;
        QBoxLayout*  planesLayout;
        QGridLayout* gridPlaneLayout;
        QGridLayout* headerLayout;
        QGridLayout* footerLayout;
        QGridLayout* dataAndLegendLayout;
        QSpacerItem* leftOuterSpacer;
        QSpacerItem* rightOuterSpacer;
        QSpacerItem* topOuterSpacer;
        QSpacerItem* bottomOuterSpacer;

        QVBoxLayout* innerHdFtLayouts[2][3][3];

        QVector<KDChart::TextArea*> textLayoutItems;
        QVector<KDChart::AbstractLayoutItem*> planeLayoutItems;
        QVector<KDChart::Legend*> legendLayoutItems;

        QSize overrideSize;
        bool isFloatingLegendsLayoutDirty;
        bool isPlanesLayoutDirty;

        // since we do not want to derive Chart from AbstractAreaBase, we store the attributes
        // here and call two static painting methods to draw the background and frame.
        KDChart::FrameAttributes frameAttributes;
        KDChart::BackgroundAttributes backgroundAttributes;

        // ### wrong names, "leading" means inter-line distance of text. spacing? margin?
        int globalLeadingLeft, globalLeadingRight, globalLeadingTop, globalLeadingBottom;

        QList< AbstractCoordinatePlane* > mouseClickedPlanes;

        Qt::LayoutDirection layoutDirection;

        Private( Chart* );

        virtual ~Private();

        void createLayouts();
        void updateDirtyLayouts();
        void reapplyInternalLayouts(); // TODO: see if this can be merged with updateDirtyLayouts()
        void paintAll( QPainter* painter );

        struct AxisInfo {
            AxisInfo()
                :plane(0)
            {}
            AbstractCoordinatePlane *plane;
        };
        QHash<AbstractCoordinatePlane*, PlaneInfo> buildPlaneLayoutInfos();
        QVector< LayoutGraphNode* > buildPlaneLayoutGraph();

    public Q_SLOTS:
        void slotLayoutPlanes();
        void slotResizePlanes();
        void slotLegendPositionChanged( AbstractAreaWidget* legend );
        void slotHeaderFooterPositionChanged( HeaderFooter* hf );
        void slotUnregisterDestroyedLegend( Legend * legend );
        void slotUnregisterDestroyedHeaderFooter( HeaderFooter* headerFooter );
        void slotUnregisterDestroyedPlane( AbstractCoordinatePlane* plane );
};

}

#endif
