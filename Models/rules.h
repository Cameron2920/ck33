#ifndef RULES_H
#define RULES_H

#include "playablecharacter.h"
#include "enemycharacter.h"
#include "floor.h"
#include "chamber.h"
#include "goldpile.h"
#include "dragon.h"
#include <math.h>
#include <stdlib.h>
#include <typeinfo>


class Rules {
public:
    Rules();
    Rules(int numberOfEnemiesPerFloor);
    bool hasPlayerWon(PlayableCharacter* player);
    bool hasPlayerCompletedFloor(PlayableCharacter* player, Floor* floor);
    bool hasPlayerLost(PlayableCharacter* player);
    bool canCharacterAttackCharacter(Character* attacker, Character* target);
    bool didCharacterHitCharacter(Character* attacker, Character* target);
    int calculateDamageGivenFromCharacterToCharacter(Character* attacker, Character* target);
    bool canPlayerCollectGoldPile(Character* character, GoldPile* goldPile, Floor* floor);
    bool canPlayerMoveToCell(PlayableCharacter* character, Cell* cell, Floor* floor);
    bool canEnemyPlayerMoveToCell(EnemyCharacter* character, Cell* cell, Floor* floor);
    bool isCharacterAlive(Character* character);
private:
    int numberOfEnemiesPerFloor;
};

#endif // RULES_H
