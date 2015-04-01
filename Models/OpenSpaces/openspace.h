#ifndef OPENSPACE_H
#define OPENSPACE_H

#ifdef CONNECTOR_H
class Connector;
#else
#include "Cells/connector.h"
#endif

#include "Cells/resizeablecellarray.h"
#include "Cells/wall.h"

#include <typeinfo>
#include <iostream>

class OpenSpace {
public:
    OpenSpace();
    OpenSpace(int cellsCapacity);
    virtual ~OpenSpace();
    void addConnector(Connector* connector);
    bool isContainingCell(Cell* cell);
    void addCell(Cell* cell);
    ResizeableCellArray* getUnoccupiedCells();
    void setUnoccupiedCells(ResizeableCellArray* cells);
    ResizeableCellArray* getCells();
    void setCells(ResizeableCellArray* cells);
    virtual ResizeableArray<Connector>* getConnectors();
    virtual void setConnectors(ResizeableArray<Connector>* connectors);
    bool isCellConnected(Cell* cell);
    bool isOpenSpaceConnected(OpenSpace* openSpace);
    int maxColumnCoordinate();
    int maxRowCoordinate();
    Cell* findCellByCoordinates(int rowCoordinate, int columnCoordinate);
    void setCellEntity(Cell* cell, Entity* entity);
    void appendOpenSpace(OpenSpace*oOpenSpace);
private:
    ResizeableCellArray* cells;
    ResizeableCellArray* unoccupiedCells;
    ResizeableArray<Connector>* connectors;
};

#endif // OPENSPACE_H
