#ifndef CELL_H
#define CELL_H

#ifdef ENTITY_H
class Entity;
#else
#include "entity.h"
#endif

#ifdef RESIZEABLECELLARRAY_H
class ResizeableCellArray;
#else
#include "resizeablecellarray.h"
#endif

#include <iostream>

#define MAX_NUMBER_OF_CELL_NEIGHBOURS 9
class Cell {
public:
    Cell();
    virtual ~Cell();
    Cell(int rowCoordinate, int columnCoordinate);
    Cell(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter);
    Entity* getEntity();
    void setEntity(Entity* entity);
    void addCellNeighbour(Cell* cell);
    bool isInCellNeighbours(Cell* cell);
    bool isInUnoccupiedCellNeighbours(Cell* cell);
    bool isNeighbourCell(Cell* cell);
    int getRowCoordinate();
    void setRowCoordinate(int rowCoordinate);
    int getColumnCoordinate();
    void setColumnCoordinate(int columnCoordinate);
    ResizeableCellArray* getCellNeigbours();
    ResizeableCellArray* getUnoccupiedCellNeigbours();
    char getTerminalDisplayCharacter();
    void setTerminalDisplayCharacter(char terminalDisplayCharacter);
    bool isConnected(Cell* cell);
    void setCanBeOccupied(bool canBeOccupied);
    bool isOccupiable();

private:
    bool canBeOccupied;
    Entity* entity;
    int rowCoordinate;
    int columnCoordinate;
    ResizeableCellArray* cellNeighbours;
    ResizeableCellArray* unoccupiedCellNeighbours;
    char terminalDisplayCharacter;
    void notifyNeighboursOccupancy();

    friend std::ostream& operator<<(std::ostream& os, Cell* cell);
};

#endif // CELL_H
