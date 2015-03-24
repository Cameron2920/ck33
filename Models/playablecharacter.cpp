#include "playablecharacter.h"

PlayableCharacter::PlayableCharacter(){}

PlayableCharacter::PlayableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race):MoveableCharacter(healthPoints, defensePoints, attackPoints, race), hasAttackedMerchant(false){}

void PlayableCharacter::consumePotion(Potion *potion){
    applyPotionEffect(potion);
    consumedPotions->add(potion);
}

void PlayableCharacter::collectGoldPile(GoldPile *goldPile){
    valueOfGoldCollected += goldPile->getValue();
}

void PlayableCharacter::digestPotions(){
    for(int potionIndex = 0; potionIndex < numberOfConsumedPotions; potionIndex++){
        Potion* potion = consumedPotions->getAt(consumedPotions->getNumberOfElements() - 1);
        unapplyPotionEffect(potion);
        consumedPotions->remove(potion);
    }
}

void PlayableCharacter::applyPotionEffect(Potion* potion){
    if(potion->getEffectedAttribute() == Potion::HealthPoints){
        this->setHealthPoints(this->getHealthPoints() + potion->getEffectAmount());
    }
    else if(potion->getEffectedAttribute()  == Potion::AttackPoints){
        this->setAttackPoints(this->getAttackPoints() + potion->getEffectAmount());
    }
    else if(potion->getEffectedAttribute() == Potion::DefensePoints){
        this->setDefensePoints(this->getDefensePoints() + potion->getEffectAmount());
    }
}

void PlayableCharacter::unapplyPotionEffect(Potion* potion){
    if(potion->getEffectedAttribute() == Potion::HealthPoints){
        this->setHealthPoints(this->getHealthPoints() - potion->getEffectAmount());
    }
    else if(potion->getEffectedAttribute()  == Potion::AttackPoints){
        this->setAttackPoints(this->getAttackPoints() - potion->getEffectAmount());
    }
    else if(potion->getEffectedAttribute() == Potion::DefensePoints){
        this->setDefensePoints(this->getDefensePoints() - potion->getEffectAmount());
    }
}
