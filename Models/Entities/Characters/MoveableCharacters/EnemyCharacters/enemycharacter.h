#ifndef ENEMYCHARACTER_H
#define ENEMYCHARACTER_H
#include "Entities/goldpile.h"
#include "Entities/Characters/MoveableCharacters/moveablecharacter.h"

class EnemyCharacter : public MoveableCharacter{
public:
    EnemyCharacter();
    EnemyCharacter(int healthPoints, int defensePoints, int attackPoints, Race race);
    EnemyCharacter(int healthPoints, int defensePoints, int attackPoints, Race race, GoldPile* goldPile);
    virtual ~EnemyCharacter();
    GoldPile* getGoldPile();
    void setGoldPile(GoldPile* goldPile);
private:
    GoldPile* goldPile;
};

#endif // ENEMYCHARACTER_H
