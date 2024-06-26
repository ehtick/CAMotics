/******************************************************************************\

  CAMotics is an Open-Source simulation and CAM software.
  Copyright (C) 2011-2019 Joseph Coffland <joseph@cauldrondevelopment.com>

  This program is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 2 of the License, or
  (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.

  You should have received a copy of the GNU General Public License
  along with this program.  If not, see <http://www.gnu.org/licenses/>.

\******************************************************************************/

#pragma once


#include "Entity.h"

#include <dxflib/dl_creationadapter.h>

#include <cbang/io/InputSource.h>

#include <map>
#include <string>
#include <vector>


namespace DXF {
  class Reader : public DL_CreationAdapter {
  public:
    typedef std::vector<cb::SmartPointer<Entity> > layer_t;
    typedef std::map<std::string, layer_t> layers_t;

  protected:
    layers_t layers;

    cb::SmartPointer<Entity> entity;

    bool inBlock;
    bool warnEllipse;
    bool warn3DFace;
    bool warnSolid;

  public:
    Reader() :
      inBlock(false), warnEllipse(true), warn3DFace(true), warnSolid(true) {}

    void read(const cb::InputSource &source);

    const layers_t &getLayers() const {return layers;}

    void addEntity(const cb::SmartPointer<Entity> &entity);

    // From DL_CreationAdapter
    void addLayer(const DL_LayerData &data) override;
    void addBlock(const DL_BlockData &block) override {inBlock = true;}
    void endBlock() override {inBlock = false;}
    void addPoint(const DL_PointData &point) override;
    void addLine(const DL_LineData &line) override;
    void addArc(const DL_ArcData &arc) override;
    void addCircle(const DL_CircleData &circle) override;
    void addPolyline(const DL_PolylineData &polyline) override;
    void addVertex(const DL_VertexData &vertex) override;
    void addSpline(const DL_SplineData &spline) override;
    void addControlPoint(const DL_ControlPointData &ctrlPt) override;
    void addKnot(const DL_KnotData &knot) override;
    void endEntity() override {entity = 0;}
    void addEllipse(const DL_EllipseData &ellipse) override;
    void add3dFace(const DL_3dFaceData &face) override;
    void addSolid(const DL_SolidData &solid) override;
  };
}
