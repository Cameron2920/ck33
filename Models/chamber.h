#ifndef CHAMBER_H
#define CHAMBER_H
#include "openspace.h"
#include "enemycharacter.h"
#include "potion.h"
#include "goldpile.h"
#include "wall.h"
#include "resizeablearray.h"

#ifdef DOORWAY_H
class Doorway;
#else
#include "doorway.h"
#endif

class Chamber : public OpenSpace{
public:
    Chamber();
    EnemyCharacter** getEnemies();
    int getNumberOfEnemies();
    void addEnemy(EnemyCharacter* enemy);
    void addPotion(Potion* potion);
    void addGoldPile(GoldPile* goldPile);
    ResizeableArray<EnemyCharacter>* getEnemies();
    ResizeableArray<Potion>* getPotions();
    ResizeableArray<GoldPile>* getGoldPiles();
private:
    ResizeableArray<EnemyCharacter>* enemies;
    ResizeableArray<Potion>* potions;
    ResizeableArray<GoldPile>* goldPiles;
    ResizeableArray<Doorway>* doorways;
    ResizeableArray<Wall>* walls;
};

#endif // CHAMBER_H
