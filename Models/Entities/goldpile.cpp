#include "goldpile.h"

GoldPile::GoldPile():Entity(),value(0){}

GoldPile::GoldPile(int value):Entity(),value(value){}

int GoldPile::getValue(){
    return value;
}

void GoldPile::setValue(int value){
    this->value = value;
}
