#ifndef ARTIFICIALINTELLIGENCE_H
#define ARTIFICIALINTELLIGENCE_H
#include "moveablecharacter.h"
#include "rules.h"
#include "floor.h"
#include <stdlib.h>
#include <typeinfo>

class ArtificialIntelligence
{
public:
    ArtificialIntelligence();
    void simulateEnemyCharacter(MoveableCharacter* enemyCharacter, MoveableCharacter* targetCharacter, Rules* rules, Floor* floor);
private:
    void simulateEnemyCharacterMove(MoveableCharacter* enemyCharacter, Rules* rules, Floor* floor);
};

#endif // ARTIFICIALINTELLIGENCE_H
