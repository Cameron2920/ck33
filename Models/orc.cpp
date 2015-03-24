#include "orc.h"

Orc::Orc():PlayableCharacter(180, 30, 35, Character::Orc){}

void PlayableCharacter::collectGoldPile(GoldPile *goldPile){
    valueOfGoldCollected += (goldPile->getValue() / 2);
    delete goldPile;
}
