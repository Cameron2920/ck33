#include "goldpile.h"

GoldPile::GoldPile():value(0){}

GoldPile::GoldPile(int value):value(value){}

int GoldPile::getValue(){
    return value;
}

void GoldPile::setValue(int value){
    this->value = value;
}
