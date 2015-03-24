#include "potion.h"

Potion::Potion():effectAmount(0){}

Potion::Potion(EffectedAttribute effectedAttribute, int effectAmount):effectAmount(effectAmount), effectedAttribute(effectedAttribute){}

void Potion::setEffectAmout(int effectAmount){
    this->effectAmount = effectAmount;
}

int Potion::getEffectAmount(){
    return effectAmount;
}

void Potion::setEffectedAttribute(EffectedAttribute effectedAttribute){
    this->effectedAttribute = effectedAttribute;
}

Potion::EffectedAttribute Potion::getEffectedAttribute(){
    return effectedAttribute;
}
