#ifndef INITIALIZER_H
#define INITIALIZER_H
#include "floor.h"
#include "werewolf.h"
#include "phoenix.h"
#include "vampire.h"
#include "goblin.h"
#include "troll.h"
#include "merchant.h"
#include "dragon.h"
#include "playablecharacter.h"
#include <stdlib.h>

class Initializer
{
public:
    Initializer();
    void intializeFloor(Floor* floor, int numberOfEnemies, int numberOfPotions, int numberOfGoldPiles, PlayableCharacter* player);
private:
    void initializeLadder(Floor* floor);
    void initializePlayer(Floor* floor, PlayableCharacter* player);
    void initializeFloorEnemies(Floor* floor, int numberOfEnemies);
    void initializeFloorPotions(Floor* floor, int numberOfPotions);
    void initializeFloorGoldPiles(Floor* floor, int numberOfGoldPiles);
    EnemyCharacter* createRandomEnemyCharacter();
    Chamber* selectRandomChamber(ResizeableArray<Chamber>* availableChambers);
    Cell* selectRandomCellFromChamber(Chamber* chamber);
    Potion* createRandomPotion();
};

#endif // INITIALIZER_H
