#ifndef ENTITY_H
#define ENTITY_H

#ifdef CELL_H
class Cell;
#else
#include "Cells/cell.h"
#endif

#include <iostream>

class Entity {
public:
    Entity();
    Entity(char terminalDisplayCharacter);
    Cell* getCell();
    virtual ~Entity();
    void setCell(Cell* cell);
    char getTerminalDisplayCharacter();
    void setTerminalDisplayCharacter(char terminalDisplayCharacter);
private:
    Cell* cell;
    char terminalDisplayCharacter;
    friend std::ostream& operator<<(std::ostream& os, Entity* entity);
};

#endif // ENTITY_H
