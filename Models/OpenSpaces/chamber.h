#ifndef CHAMBER_H
#define CHAMBER_H
#include "OpenSpaces/openspace.h"
#include "Entities/Characters/MoveableCharacters/EnemyCharacters/enemycharacter.h"
#include "Entities/potion.h"
#include "Entities/goldpile.h"
#include "Cells/wall.h"
#include "resizeablearray.t.hpp"

#ifdef DOORWAY_H
class Doorway;
#else
#include "Cells/doorway.h"
#endif

class Chamber : public OpenSpace{
public:
    Chamber();
    virtual ~Chamber();
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
    void removeAllEnemies();
    void removeAllPotions();
    void removeAllGoldPiles();
    void removeAllEntities();
    virtual ResizeableArray<Connector>* getConnectors();
    virtual void setConnectors(ResizeableArray<Connector>* connectors);
private:
    ResizeableArray<EnemyCharacter>* enemies;
    ResizeableArray<Potion>* potions;
    ResizeableArray<GoldPile>* goldPiles;
    ResizeableArray<Doorway>* doorways;
    ResizeableArray<Wall>* walls;
};

#endif // CHAMBER_H
