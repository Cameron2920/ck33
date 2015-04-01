#include "potion.h"

Potion::Potion():Entity(),effectAmount(0){}

Potion::Potion(EffectedAttribute effectedAttribute, int effectAmount):Entity(),effectAmount(effectAmount), effectedAttribute(effectedAttribute){}

Potion::Potion(Potion* potion):Entity(),effectAmount(potion->getEffectAmount()), effectedAttribute(potion->getEffectedAttribute()){}

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
