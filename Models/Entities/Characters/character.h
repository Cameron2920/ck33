#ifndef CHARACTER_H
#define CHARACTER_H
#include "Entities/entity.h"
#include <iostream>

class Character : public Entity {
public:
    enum Race { Werewolf, Vampire, Goblin, Merchant, Dragon, Phoenix, Troll, Human, Dwarf, Elf, Orc };
    Character();
    Character(int healthPoints, int defensePoints, int attackPoints, Race race);
    int getHealthPoints();
    void setHealthPoints(int healthPoints);
    int getAttackPoints();
    void setAttackPoints(int attackPoints);
    int getDefensePoints();
    void setDefensePoints(int defensePoints);
    Race getRace();
    void attackCharacter(Character* character, int damagePoints);
private:
    int healthPoints;
    int attackPoints;
    int defensePoints;
    Race race;
};

#endif // CHARACTER_H
