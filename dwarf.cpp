#include "dwarf.h"

Dwarf::Dwarf():PlayableCharacter(100, 20, 30, Character::Dwarf){}

void PlayableCharacter::collectGoldPile(GoldPile *goldPile){
    valueOfGoldCollected += (2 * goldPile->getValue());
    delete goldPile;
}
