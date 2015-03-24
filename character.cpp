#include "character.h"

Character::Character(){}

Character::Character(int healthPoints, int defensePoints, int attackPoints, Race race):healthPoints(healthPoints), defensePoints(defensePoints),attackPoints(attackPoints),race(race){}
int Character::getHealthPoints(){
    return healthPoints;
}

void Character::setHealthPoints(int healthPoints){
    if(healthPoints > 100){
        this->healthPoints = 100;
    }
    else if(healthPoints < 0){
        this->healthPoints = 0;
    }
    else{
        this->healthPoints = healthPoints;
    }
}

int Character::getAttackPoints(){
    return attackPoints;
}

void Character::setAttackPoints(int attackPoints){
    if(attackPoints > 100){
        this->attackPoints = 100;
    }
    else if(attackPoints < 0){
        this->attackPoints = 0;
    }
    else {
        this->attackPoints = attackPoints;
    }
}

int Character::getDefensePoints(){
    return defensePoints;
}

void Character::setDefensePoints(int defensePoints){
    if(defensePoints > 100){
        this->defensePoints = 100;
    }
    else if(defensePoints < 0){
        this->defensePoints = 0;
    }
    else{
        this->defensePoints = defensePoints;
    }
}

void Character::attackCharacter(Character *character, int damagePoints){
    character->setHealthPoints(character->getHealthPoints() - damagePoints);
}
