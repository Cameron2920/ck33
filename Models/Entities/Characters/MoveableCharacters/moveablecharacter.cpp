#include "moveablecharacter.h"

MoveableCharacter::MoveableCharacter():Character() {}

MoveableCharacter::MoveableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race):Character(healthPoints, defensePoints, attackPoints, race){}

void MoveableCharacter::moveToCell(Cell *cell){
    Cell* previousCell = getCell();
    previousCell->setEntity(0);
    setCell(cell);
    cell->setEntity(this);
}
