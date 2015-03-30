#include "wall.h"

Wall::Wall():Cell(){
    setCanBeOccupied(false);
}

Wall::Wall(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter):Cell(rowCoordinate, columnCoordinate, terminalDisplayCharacter){
    setCanBeOccupied(false);
}
