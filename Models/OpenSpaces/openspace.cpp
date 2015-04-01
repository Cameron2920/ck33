#include "openspace.h"

OpenSpace::OpenSpace(){
    cells = new ResizeableCellArray;
    unoccupiedCells = new ResizeableCellArray;
    connectors = new ResizeableArray<Connector>;
}

OpenSpace::OpenSpace(int cellsCapacity){
    cells = new ResizeableCellArray(cellsCapacity);
    unoccupiedCells = new ResizeableCellArray(cellsCapacity);
    connectors = new ResizeableArray<Connector>;
}

OpenSpace::~OpenSpace(){
    delete cells;
    delete connectors;
    delete unoccupiedCells;
}

void OpenSpace::addConnector(Connector *connector){
    connectors->add(connector);
    addCell(connector);
}

bool OpenSpace::isContainingCell(Cell *cell){
    for(int cellIndex = 0; cellIndex < cells->getNumberOfElements(); cellIndex++){

        if(cell == cells->getAt(cellIndex)){
            return true;
        }
    }
    return false;
}

void OpenSpace::addCell(Cell *cell){
    cells->add(cell);
    if(cell->isOccupiable()){
        unoccupiedCells->add(cell);
    }

    for(int cellIndex = 0; cellIndex < cells->getNumberOfElements(); cellIndex++){
        cell->addCellNeighbour(cells->getAt(cellIndex));
        cells->getAt(cellIndex)->addCellNeighbour(cell);
    }
}

bool OpenSpace::isCellConnected(Cell *cell){
    for(int cellIndex = 0; cellIndex < cells->getNumberOfElements(); cellIndex++){
        if(cells->getAt(cellIndex)->isConnected(cell)){
            return true;
        }
    }
    return false;
}

bool OpenSpace::isOpenSpaceConnected(OpenSpace *openSpace){
    ResizeableCellArray* openSpaceCells = openSpace->getCells();
    for(int cellIndex = 0; cellIndex < openSpaceCells->getNumberOfElements(); cellIndex++){
        if(isCellConnected(openSpaceCells->getAt(cellIndex))){
            return true;
        }
    }
    return false;
}

void OpenSpace::setConnectors(ResizeableArray<Connector> *connectors){
    this->connectors = connectors;
}

ResizeableArray<Connector>* OpenSpace::getConnectors(){
    return connectors;
}

void OpenSpace::setCells(ResizeableCellArray* cells){
    this->cells = cells;
}

ResizeableCellArray* OpenSpace::getCells(){
    return cells;
}

int OpenSpace::maxColumnCoordinate(){
    return cells->getMaxColumnCoordinate();
}

int OpenSpace::maxRowCoordinate(){
    return cells->getMaxRowCoordinate();
}

Cell* OpenSpace::findCellByCoordinates(int rowCoordinate, int columnCoordinate){
    return cells->findByCoordinates(rowCoordinate, columnCoordinate);
}

ResizeableCellArray* OpenSpace::getUnoccupiedCells(){
    return unoccupiedCells;
}

void OpenSpace::setUnoccupiedCells(ResizeableCellArray *unoccupiedCells){
    this->unoccupiedCells = unoccupiedCells;
}

void OpenSpace::setCellEntity(Cell *cell, Entity *entity){
    cell->setEntity(entity);
    entity->setCell(cell);
    unoccupiedCells->pop(cell);
}

void OpenSpace::appendOpenSpace(OpenSpace *openSpace){
    for(int cellIndex = 0; cellIndex < openSpace->getCells()->getNumberOfElements(); cellIndex++){
        addCell(openSpace->getCells()->getAt(cellIndex));
    }
    unoccupiedCells->append(openSpace->getUnoccupiedCells());
    connectors->append(openSpace->getConnectors());
}
