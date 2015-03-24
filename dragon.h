#ifndef DRAGON_H
#define DRAGON_H
#include "goldpile.h"
#include "enemycharacter.h"

class Dragon : public EnemyCharacter {
public:
    Dragon();
    Dragon(GoldPile* goldPile);
    GoldPile* getGoldPile();
    void setGoldPile(GoldPile* goldPile);
private:
    GoldPile* goldPile;
};

#endif // DRAGON_H
