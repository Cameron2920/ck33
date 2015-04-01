#include "orc.h"

Orc::Orc():PlayableCharacter(180, 30, 35, Character::Orc){}

void Orc::collectGoldPile(GoldPile *goldPile){
    setValueOfGoldCollected(getValueOfGoldCollected() + (goldPile->getValue() / 2));
    delete goldPile;
}
