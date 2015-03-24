#ifndef MOVEABLECHARACTER_H
#define MOVEABLECHARACTER_H

#include "character.h"
#include "cell.h"
#include <typeinfo>

class MoveableCharacter : public Character {
public:
    MoveableCharacter();
    MoveableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race);
    void moveToCell(Cell* cell);
};
#endif // MOVEABLECHARACTER_H
