#include "enemycharacter.h"

EnemyCharacter::EnemyCharacter(){}

EnemyCharacter::EnemyCharacter(int healthPoints, int defensePoints, int attackPoints, Race race):MoveableCharacter(healthPoints, defensePoints, attackPoints, race){}

EnemyCharacter::EnemyCharacter(int healthPoints, int defensePoints, int attackPoints, Race race, GoldPile* goldPile):MoveableCharacter(healthPoints, defensePoints, attackPoints, race), goldPile(goldPile){}

void EnemyCharacter::setGoldPile(GoldPile *goldPile){
    this->goldPile = goldPile;
}

GoldPile* EnemyCharacter::getGoldPile(){
    return goldPile;
}
