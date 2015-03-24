#include "elf.h"

Elf::Elf():PlayableCharacter(140 ,30, 10, Character::Elf){}

void PlayableCharacter::applyPotionEffect(Potion *potion){
    if(potion->getEffectedAttribute() == Potion::HealthPoints){
        this->setHealthPoints(this->getHealthPoints() + std::abs(potion->getEffectAmount()));
    }
    else if(potion->getEffectedAttribute()  == Potion::AttackPoints){
        this->setAttackPoints(this->getAttackPoints() + std::abs(potion->getEffectAmount()));
    }
    else if(potion->getEffectedAttribute() == Potion::DefensePoints){
        this->setDefensePoints(this->getDefensePoints() + std::abs(potion->getEffectAmount()));
    }
}

void PlayableCharacter::unapplyPotionEffect(Potion *potion){
    if(potion->getEffectedAttribute() == Potion::HealthPoints){
        this->setHealthPoints(this->getHealthPoints() - std::abs(potion->getEffectAmount()));
    }
    else if(potion->getEffectedAttribute()  == Potion::AttackPoints){
        this->setAttackPoints(this->getAttackPoints() - std::abs(potion->getEffectAmount()));
    }
    else if(potion->getEffectedAttribute() == Potion::DefensePoints){
        this->setDefensePoints(this->getDefensePoints() - std::abs(potion->getEffectAmount()));
    }
}
