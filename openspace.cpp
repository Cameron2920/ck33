#include "openspace.h"

OpenSpace::OpenSpace():cellsCapacity(0), numberOfCells(0), numberOfConnectors(0){}

OpenSpace::OpenSpace(int cellsCapacity):cellsCapacity(cellsCapacity), numberOfCells(0), numberOfConnectors(0){
    cells = new Cell*[cellsCapacity];
    unoccupiedCells = new Cell*[cellsCapacity];
}

void OpenSpace::addConnector(Connector *connector){
    connectors->add(connector);

    if(!connector->getConnectedOpenSpace1()){
        connector->setConnectedOpenSpace1(this);
    }
    else if(!connector->getConnectedOpenSpace2()){
        connector->setConnectedOpenSpace2(this);
    }

    for(int cellIndex = 0; cellIndex < numberOfCells; cellIndex++){
        cell->addCellNeighbour(cells->getAt(cellIndex));
        cells->getAt(cellsIndex)->addCellNeighbour(cell);
    }
}

bool OpenSpace::isContainingCell(Cell *cell){
    for(int cellIndex = 0; cellIndex < numberOfCells; cellIndex++){

        if(cell == cells[cellIndex]){
            return true;
        }
    }
    return false;
}

void OpenSpace::addCell(Cell *cell){
    cells->add(cell);

    for(int cellIndex = 0; cellIndex < numberOfCells; cellIndex++){
        cell->addCellNeighbour(cells->getAt(cellIndex));
        cells->getAt(cellsIndex)->addCellNeighbour(cell);
    }
}
