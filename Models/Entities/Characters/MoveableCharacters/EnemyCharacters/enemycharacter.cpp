#include "enemycharacter.h"

EnemyCharacter::EnemyCharacter():MoveableCharacter(),goldPile(0){}

EnemyCharacter::EnemyCharacter(int healthPoints, int defensePoints, int attackPoints, Race race):MoveableCharacter(healthPoints, defensePoints, attackPoints, race),goldPile(0){}

EnemyCharacter::EnemyCharacter(int healthPoints, int defensePoints, int attackPoints, Race race, GoldPile* goldPile):MoveableCharacter(healthPoints, defensePoints, attackPoints, race), goldPile(goldPile){}

EnemyCharacter::~EnemyCharacter(){
    if(goldPile){
        delete goldPile;
    }
}

void EnemyCharacter::setGoldPile(GoldPile *goldPile){
    this->goldPile = goldPile;
}

GoldPile* EnemyCharacter::getGoldPile(){
    return goldPile;
}
