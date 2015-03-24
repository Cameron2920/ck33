#ifndef OPENSPACE_H
#define OPENSPACE_H

#ifdef CONNECTOR_H
class Connector;
#else
#include "connector.h"
#endif

#include "resizeablearray.h"

#include <iostream>

class OpenSpace {
public:
    OpenSpace();
    OpenSpace(int cellsCapacity);
    void addConnector(Connector* connector);
    bool isContainingCell(Cell* cell);
    void addCell(Cell* cell);
    int getNumberOfEntities();
    Cell** getUnoccupiedCells();
    ResizeableArray<Cell>* getCells();
private:
    ResizeableArray<Cell>* cells;
    ResizeableArray<Connector>* connectors;
};

#endif // OPENSPACE_H
