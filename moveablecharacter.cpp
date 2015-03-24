#include "moveablecharacter.h"

MoveableCharacter::MoveableCharacter() {}

MoveableCharacter::MoveableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race):Character(healthPoints, defensePoints, attackPoints, race){}

void MoveableCharacter::moveToCell(Cell *cell){
    setCell(cell);
    cell->setEntity(this);
}
