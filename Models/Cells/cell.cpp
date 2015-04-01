#include "cell.h"

Cell::Cell():entity(0),canBeOccupied(true){
    cellNeighbours = new ResizeableCellArray(MAX_NUMBER_OF_CELL_NEIGHBOURS);
    unoccupiedCellNeighbours = new ResizeableCellArray(MAX_NUMBER_OF_CELL_NEIGHBOURS);
}

Cell::Cell(int rowCoordinate, int columnCoordinate):rowCoordinate(rowCoordinate), columnCoordinate(columnCoordinate), entity(0), canBeOccupied(true){
    cellNeighbours = new ResizeableCellArray(MAX_NUMBER_OF_CELL_NEIGHBOURS);
    unoccupiedCellNeighbours = new ResizeableCellArray(MAX_NUMBER_OF_CELL_NEIGHBOURS);
}

Cell::Cell(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter):rowCoordinate(rowCoordinate), columnCoordinate(columnCoordinate), terminalDisplayCharacter(terminalDisplayCharacter), entity(0), canBeOccupied(true){
    cellNeighbours = new ResizeableCellArray(MAX_NUMBER_OF_CELL_NEIGHBOURS);
    unoccupiedCellNeighbours = new ResizeableCellArray(MAX_NUMBER_OF_CELL_NEIGHBOURS);
}

Cell::~Cell(){
    if(entity){
        entity->setCell(0);
    }

    delete cellNeighbours;
    delete unoccupiedCellNeighbours;
}

Entity* Cell::getEntity(){
    return entity;
}

void Cell::setEntity(Entity *entity){
    this->entity = entity;
    notifyNeighboursOccupancy();
}

void Cell::addCellNeighbour(Cell *cell){
    if(cellNeighbours->getNumberOfElements() < MAX_NUMBER_OF_CELL_NEIGHBOURS && !isInCellNeighbours(cell) && isNeighbourCell(cell)){
        cellNeighbours->add(cell);
        if(cell->isOccupiable()){
            unoccupiedCellNeighbours->add(cell);
        }
    }
}

bool Cell::isInCellNeighbours(Cell* cell){
    for(int neighbourIndex = 0; neighbourIndex < cellNeighbours->getNumberOfElements(); neighbourIndex++){
        if(cellNeighbours->getAt(neighbourIndex) == cell){
            return true;
        }
    }
    return false;
}

bool Cell::isInUnoccupiedCellNeighbours(Cell* cell){
    for(int neighbourIndex = 0; neighbourIndex < unoccupiedCellNeighbours->getNumberOfElements(); neighbourIndex++){
        if(unoccupiedCellNeighbours->getAt(neighbourIndex) == cell){
            return true;
        }
    }
    return false;
}

bool Cell::isNeighbourCell(Cell *cell){
    return ((cell->getColumnCoordinate() + 1) == columnCoordinate || (cell->getColumnCoordinate() - 1) == columnCoordinate || cell->getColumnCoordinate() == columnCoordinate) &&
            ((cell->getRowCoordinate() + 1) == rowCoordinate || (cell->getRowCoordinate() - 1) == rowCoordinate || cell->getRowCoordinate() == rowCoordinate) &&
            !(cell->getColumnCoordinate() == columnCoordinate && cell->getRowCoordinate() == rowCoordinate);
}

int Cell::getRowCoordinate(){
    return rowCoordinate;
}

void Cell::setRowCoordinate(int rowCoordinate){
    this->rowCoordinate = rowCoordinate;
}

int Cell::getColumnCoordinate(){
    return columnCoordinate;
}

void Cell::setColumnCoordinate(int columnCoordinate){
    this->columnCoordinate = columnCoordinate;
}

ResizeableCellArray* Cell::getCellNeigbours(){
    return cellNeighbours;
}

ResizeableCellArray* Cell::getUnoccupiedCellNeigbours(){
    return unoccupiedCellNeighbours;
}

char Cell::getTerminalDisplayCharacter(){
    return terminalDisplayCharacter;
}

void Cell::setTerminalDisplayCharacter(char terminalDisplayCharacter){
    this->terminalDisplayCharacter = terminalDisplayCharacter;
}

std::ostream& operator<<(std::ostream& os, Cell* cell){
    if(cell->getEntity()){
        os << cell->getEntity();
    }
    else{
        os << cell->getTerminalDisplayCharacter();
    }
    return os;
}

bool Cell::isConnected(Cell *cell){
    return ((cell->getColumnCoordinate() + 1) == columnCoordinate && cell->getRowCoordinate() == rowCoordinate)
            || ((cell->getColumnCoordinate() - 1) == columnCoordinate && cell->getRowCoordinate() == rowCoordinate)
            || ((cell->getRowCoordinate() + 1) == rowCoordinate && cell->getColumnCoordinate() == columnCoordinate)
            || ((cell->getRowCoordinate() - 1) == rowCoordinate && cell->getColumnCoordinate() == columnCoordinate);
}

void Cell::setCanBeOccupied(bool canBeOccupied){
    this->canBeOccupied = canBeOccupied;
    notifyNeighboursOccupancy();
}

bool Cell::isOccupiable(){
    return canBeOccupied && !getEntity();
}

void Cell::notifyNeighboursOccupancy(){
    for(int neighbourIndex = 0; neighbourIndex < cellNeighbours->getNumberOfElements(); neighbourIndex++){
        Cell* neighbourCell = cellNeighbours->getAt(neighbourIndex);
        if(isOccupiable() && !neighbourCell->isInUnoccupiedCellNeighbours(this)){
            neighbourCell->getUnoccupiedCellNeigbours()->add(this);
        }
        else if(!isOccupiable()){
            neighbourCell->getUnoccupiedCellNeigbours()->pop(this);
        }
    }
}
