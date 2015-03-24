#ifndef CELL_H
#define CELL_H

#ifdef ENTITY_H
class Entity;
#else
#include "entity.h"
#endif

#include <iostream>

#define MAX_NUMBER_OF_CELL_NEIGHBOURS 9
class Cell {
public:
    Cell();
    ~Cell();
    ~Cell(bool destroyEntity);
    Cell(int rowCoordinate, int columnCoordinate);
    Entity* getEntity();
    void setEntity(Entity* entity);
    void addCellNeighbour(Cell* cell);
    int getNumberOfNeighbours();
    void setNumberOfNeighbours(int numberOfNeighbours);
    bool isNeighbourCell(Cell* cell);
    int getRowCoordinate();
    void setRowCoordinate(int rowCoordinate);
    int getColumnCoordinate();
    void setColumnCoordinate(int columnCoordinate);
    Cell* getCellNeigbourAt(int neighbourIndex);
    char getTerminalDisplayCharacter();
    void setTerminalDisplayCharacter(char terminalDisplayCharacter);
private:
    Entity* entity;
    int rowCoordinate;
    int columnCoordinate;
    Cell* cellNeighbours[MAX_NUMBER_OF_CELL_NEIGHBOURS];
    int numberOfNeighbours;
    char terminalDisplayCharacter;
    friend std::ostream& operator<<(std::ostream, Cell* cell);
};

#endif // CELL_H
