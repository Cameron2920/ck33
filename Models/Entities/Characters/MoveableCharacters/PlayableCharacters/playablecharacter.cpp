#include "playablecharacter.h"

PlayableCharacter::PlayableCharacter():MoveableCharacter(){
    consumedPotions = new ResizeableArray<Potion>;
    discoveredPotions = new ResizeableArray<Potion>;
}

PlayableCharacter::PlayableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race):MoveableCharacter(healthPoints, defensePoints, attackPoints, race),
    hasAttackedMerchant(false), valueOfGoldCollected(0), numberOfCompletedFloors(0){
    consumedPotions = new ResizeableArray<Potion>;
    discoveredPotions = new ResizeableArray<Potion>;
}

PlayableCharacter::~PlayableCharacter(){
    digestPotions();
    delete consumedPotions;
    while(discoveredPotions->getNumberOfElements() > 0){
        discoveredPotions->remove(discoveredPotions->getAt(0));
    }
    delete discoveredPotions;
}

void PlayableCharacter::consumePotion(Potion *potion){
    applyPotionEffect(potion);
    consumedPotions->add(potion);
    if(!hasDiscoveredPotion(potion)){
        discoveredPotions->add(new Potion(potion));
    }
}

bool PlayableCharacter::hasDiscoveredPotion(Potion *potion){
    for(int potionIndex = 0; potionIndex < discoveredPotions->getNumberOfElements(); potionIndex++){
        if(discoveredPotions->getAt(potionIndex)->getEffectAmount() == potion->getEffectAmount() && discoveredPotions->getAt(potionIndex)->getEffectedAttribute() == potion->getEffectedAttribute()){
            return true;
        }
    }
    return false;
}

void PlayableCharacter::collectGoldPile(GoldPile *goldPile){
    valueOfGoldCollected += goldPile->getValue();
}

void PlayableCharacter::digestPotions(){
    while(consumedPotions->getNumberOfElements() > 0){
        Potion* potion = consumedPotions->getAt(0);
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

void PlayableCharacter::setValueOfGoldCollected(int valueOfGoldCollected){
    this->valueOfGoldCollected = valueOfGoldCollected;
}

int PlayableCharacter::getValueOfGoldCollected(){
    return valueOfGoldCollected;
}

int PlayableCharacter::getNumberOfCompletedFloors(){
    return numberOfCompletedFloors;
}

bool PlayableCharacter::getHasAttackedMerchant(){
    return hasAttackedMerchant;
}

void PlayableCharacter::setHasAttackedMerchant(bool hasAttackedMerchant){
    this->hasAttackedMerchant = hasAttackedMerchant;
}

std::ostream& operator<<(std::ostream& os, PlayableCharacter* player){
    std::string raceString;
    if(player->getRace() == Character::Elf){
        raceString = "Elf";
    }
    else if(player->getRace() == Character::Human){
        raceString = "Human";
    }
    else if(player->getRace() == Character::Orc){
        raceString = "Orc";
    }
    else if(player->getRace() == Character::Dwarf){
        raceString = "Dwarf";
    }
    os << "Gold: " << player->getValueOfGoldCollected() << " Race: " << raceString << "            " << "Floor " << player->getNumberOfCompletedFloors() + 1 << std::endl;
    os << "HP: "<< player->getHealthPoints() << std::endl;
    os << "Atk: " << player->getAttackPoints() << std::endl;
    os << "Def: " << player->getDefensePoints() << std::endl;
    return os;
}

void PlayableCharacter::incrementNumberOfCompletedFloors(){
    numberOfCompletedFloors++;
}
