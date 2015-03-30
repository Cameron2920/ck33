#ifndef OPENSPACE_H
#define OPENSPACE_H

#ifdef CONNECTOR_H
class Connector;
#else
#include "connector.h"
#endif

#include "resizeablecellarray.h"
#include "wall.h"

#include <typeinfo>
#include <iostream>

class OpenSpace {
public:
    OpenSpace();
    OpenSpace(int cellsCapacity);
    ~OpenSpace();
    void addConnector(Connector* connector);
    bool isContainingCell(Cell* cell);
    void addCell(Cell* cell);
    ResizeableCellArray* getUnoccupiedCells();
    void setUnoccupiedCells(ResizeableCellArray* cells);
    ResizeableCellArray* getCells();
    void setCells(ResizeableCellArray* cells);
    ResizeableArray<Connector>* getConnectors();
    void setConnectors(ResizeableArray<Connector>* connectors);
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
