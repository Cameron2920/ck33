#ifndef CHAMBER_H
#define CHAMBER_H
#include "openspace.h"
#include "enemycharacter.h"
#include "potion.h"
#include "goldpile.h"
#include "wall.h"
#include "resizeablearray.t.hpp"

#ifdef DOORWAY_H
class Doorway;
#else
#include "doorway.h"
#endif

class Chamber : public OpenSpace{
public:
    Chamber();
    int getNumberOfEnemies();
    void addEnemy(EnemyCharacter* enemy, Cell* cell);
    void addPotion(Potion* potion, Cell* cell);
    void addGoldPile(GoldPile* goldPile, Cell* cell);
    void addWall(Wall* wall);
    void addDoorway(Doorway* doorway);
    ResizeableArray<EnemyCharacter>* getEnemies();
    ResizeableArray<Potion>* getPotions();
    ResizeableArray<GoldPile>* getGoldPiles();
    ResizeableArray<Doorway>* getDoorways();
    ResizeableArray<Wall>* getWalls();
    void appendChamber(Chamber* chamber);
private:
    ResizeableArray<EnemyCharacter>* enemies;
    ResizeableArray<Potion>* potions;
    ResizeableArray<GoldPile>* goldPiles;
    ResizeableArray<Doorway>* doorways;
    ResizeableArray<Wall>* walls;
};

#endif // CHAMBER_H
