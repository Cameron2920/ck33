#include "dwarf.h"

Dwarf::Dwarf():PlayableCharacter(100, 20, 30, Character::Dwarf){}

void Dwarf::collectGoldPile(GoldPile *goldPile){
    setValueOfGoldCollected(getValueOfGoldCollected() + (2 * goldPile->getValue()));
    delete goldPile;
}
