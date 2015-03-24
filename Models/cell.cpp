#include "cell.h"

Cell::Cell():numberOfNeighbours(0){}

Cell::Cell(int rowCoordinate, int columnCoordinate):rowCoordinate(rowCoordinate), columnCoordinate(columnCoordinate), numberOfNeighbours(0){}

Cell::~Cell(){
    if(entity){
        entity->setCell(0);
    }
    if(cellNeighbours){
        delete [] cellNeighbours;
    }
}

Cell::~Cell(bool destroyEntity){
    if(destroyEntity){
        delete entity;
    }
    ~Cell();
}

Entity* Cell::getEntity(){
    return entity;
}

void Cell::setEntity(Entity *entity){
    this->entity = entity;
}

void Cell::addCellNeighbour(Cell *cell){
    if(numberOfNeighbours < MAX_NUMBER_OF_CELL_NEIGHBOURS && !isNeighbourCell(cell)){
        cellNeighbours[numberOfNeighbours] = cell;
        numberOfNeighbours++;
    }
}

bool Cell::isNeighbourCell(Cell *cell){
    for(int neighbourIndex = 0; neighbourIndex < numberOfNeighbours; neighbourIndex++){
        if(cellNeighbours[neighbourIndex] == cell){
            return true;
        }
    }
    return ((cell->getColumnCoordinate() + 1) == columnCoordinate || (cell->getColumnCoordinate() - 1) == columnCoordinate || cell->getColumnCoordinate() == columnCoordinate) &&
            ((cell->getRowCoordinate() + 1) == rowCoordinate || (cell->getRowCoordinate() - 1) == rowCoordinate || cell->getRowCoordinate() == rowCoordinate) &&
            !(cell->getColumnCoordinate() == columnCoordinate && cell->getRowCoordinate() == rowCoordinate);
}

int Cell::getNumberOfNeighbours(){
    return numberOfNeighbours;
}

void Cell::setNumberOfNeighbours(int numberOfNeighbours){
    this->numberOfNeighbours = numberOfNeighbours;
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

Cell* Cell::getCellNeigbourAt(int neighbourIndex){
    if(neighbourIndex < numberOfNeighbours){
        return cellNeighbours[neighbourIndex];
    }
    return 0;
}

char Cell::getTerminalDisplayCharacter(){
    return terminalDisplayCharacter;
}

void Cell::setTerminalDisplayCharacter(char terminalDisplayCharacter){
    this->terminalDisplayCharacter = terminalDisplayCharacter;
}

std::ostream& operator<<(std::ostream os, Cell* cell){
    if(cell->getEntity()){
        os << cell->getEntity();
    }
    else{
        os << cell->getTerminalDisplayCharacter();
    }
    return os;
}
