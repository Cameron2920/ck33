#include "rules.h"

Rules::Rules():numberOfEnemiesPerFloor(20){}

Rules::Rules(int numberOfEnemiesPerFloor):numberOfEnemiesPerFloor(numberOfEnemiesPerFloor){}

bool Rules::canPlayerMoveToCell(PlayableCharacter *character, Cell *cell, Floor *floor){
    Cell* characterCell = character->getCell();
    if(!dynamic_cast<Wall*>(cell) && cell->isInCellNeighbours(characterCell)){
        Entity* entity = cell->getEntity();
        if(!entity || (dynamic_cast<GoldPile*>(entity) && canPlayerCollectGoldPile(character, (GoldPile*) entity, floor))){
            return true;
        }
    }
    return false;
}

bool Rules::canEnemyPlayerMoveToCell(EnemyCharacter *character, Cell *cell, Floor *floor){
    Cell* characterCell = character->getCell();
    if(typeid(*cell) != typeid(Wall) && typeid(*cell) != typeid(Connector) &&
            typeid(*character) != typeid(Dragon) && cell->isNeighbourCell(characterCell) && floor->findContainingChamber(characterCell) == floor->findContainingChamber(cell)){
        Entity* entity = cell->getEntity();
        if(!entity){
            return true;
        }
    }
    return false;
}

bool Rules::hasPlayerWon(PlayableCharacter *player){
    return player->getNumberOfCompletedFloors() >= 5;
}

bool Rules::hasPlayerCompletedFloor(PlayableCharacter *player, Floor *floor){
//    return player->getCell() == floor->getLadder();
}

bool Rules::hasPlayerLost(PlayableCharacter *player){
    return player->getHealthPoints() <= 0;
}

bool Rules::canCharacterAttackCharacter(Character *attacker, Character *target){
    return attacker->getCell()->isNeighbourCell(target->getCell());
}

bool Rules::didCharacterHitCharacter(Character *attacker, Character *target){
    if(typeid(*attacker) != typeid(PlayableCharacter)){
        if(rand() % 10 >= 5){
            return false;
        }
    }
    return true;

}

bool Rules::canPlayerCollectGoldPile(Character *character, GoldPile *goldPile, Floor *floor){
    Chamber* goldPileContainingOpenSpace = floor->findContainingChamber(goldPile->getCell());
    ResizeableArray<EnemyCharacter>* enemies = goldPileContainingOpenSpace->getEnemies();
    for(int enemyIndex = 0; enemyIndex < goldPileContainingOpenSpace->getNumberOfEnemies(); enemyIndex++){
        if(typeid(enemies->getAt(enemyIndex)) == typeid(Dragon) && ((Dragon*)enemies->getAt(enemyIndex))->getGoldPile() == goldPile){
            return false;
        }
    }
    return true;
}

int Rules::calculateDamageGivenFromCharacterToCharacter(Character *attacker, Character *target){
    float damage = (100.0 / (100 + target->getDefensePoints())) * attacker->getAttackPoints();
    return (damage == (int) damage ? (int) damage : (int) damage + 1);
}

bool Rules::isCharacterAlive(Character *character){
    return character->getHealthPoints() > 0;
}
