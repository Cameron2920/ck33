#ifndef WALL_H
#define WALL_H

#include "cell.h"

#include <iostream>
class Wall : public Cell {
public:
    Wall();
    Wall(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter);
};

#endif // WALL_H
