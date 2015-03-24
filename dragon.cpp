#include "dragon.h"

Dragon::Dragon(){}

Dragon::Dragon(GoldPile* goldPile):goldPile(goldPile){}

void Dragon::setGoldPile(GoldPile *goldPile){
    this->goldPile = goldPile;
}

GoldPile* Dragon::getGoldPile(){
    return goldPile;
}
