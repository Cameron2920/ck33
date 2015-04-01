#ifndef INITIALIZER_H
#define INITIALIZER_H
#include "floor.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/werewolf.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/phoenix.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/vampire.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/goblin.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/troll.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/merchant.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/dragon.h"
#include "Entities/Characters/MoveableCharacters/PlayableCharacters/playablecharacter.h"
#include <stdlib.h>

class Initializer
{
public:
    Initializer();
    void intializeFloor(Floor* floor, int numberOfEnemies, int numberOfPotions, int numberOfGoldPiles, PlayableCharacter* player);
    void reintializeFloor(Floor* floor, int numberOfEnemies, int numberOfPotions, int numberOfGoldPiles, PlayableCharacter* player);
private:
    void initializeLadder(Floor* floor, PlayableCharacter* player);
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
