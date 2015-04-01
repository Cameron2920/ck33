#include "rules.h"

Rules::Rules():numberOfEnemiesPerFloor(20){}

Rules::Rules(int numberOfEnemiesPerFloor):numberOfEnemiesPerFloor(numberOfEnemiesPerFloor){}

bool Rules::canPlayerMoveToCell(PlayableCharacter *character, Cell *cell, Floor *floor){
    Cell* characterCell = character->getCell();
    if(!dynamic_cast<Wall*>(cell) && cell->isInCellNeighbours(characterCell)){
        Entity* entity = cell->getEntity();
        if(!entity || (dynamic_cast<GoldPile*>(entity) || dynamic_cast<Ladder*>(entity))){
            return true;
        }
    }
    return false;
}

bool Rules::canEnemyPlayerMoveToCell(EnemyCharacter *character, Cell *cell, Floor *floor){
    Cell* characterCell = character->getCell();
    if(!dynamic_cast<Connector*>(cell) && !dynamic_cast<Wall*>(cell) &&
            !dynamic_cast<Dragon*>(character) && cell->isNeighbourCell(characterCell) && floor->findContainingChamber(characterCell) == floor->findContainingChamber(cell)){
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
   return floor->getHasLadderBeenClimbed();
}

bool Rules::hasPlayerLost(PlayableCharacter *player){
    return player->getHealthPoints() <= 0;
}

bool Rules::canCharacterAttackCharacter(Character *attacker, Character *target){
    Cell* attackerCell = attacker->getCell(), *targetCell = target->getCell();
    if(dynamic_cast<Merchant*>(attacker) && dynamic_cast<PlayableCharacter*>(target) && !dynamic_cast<PlayableCharacter*>(target)->getHasAttackedMerchant()){
        return false;
    }
    if(dynamic_cast<Dragon*>(attacker) && dynamic_cast<Dragon*>(attacker)->getGoldPile()->getCell()->isInCellNeighbours(targetCell)){
        return false;
    }
    return attackerCell->isInCellNeighbours(targetCell);
}

bool Rules::didCharacterHitCharacter(Character *attacker, Character *target){
    if(dynamic_cast<EnemyCharacter*>(attacker) && rand() % 10 >= 5){
        return false;
    }
    return true;

}

bool Rules::canPlayerCollectGoldPile(Character *character, GoldPile *goldPile, Floor *floor){
    Chamber* goldPileContainingOpenSpace = floor->findContainingChamber(goldPile->getCell());
    for(int goldPileIndex = 0; goldPileIndex < goldPileContainingOpenSpace->getNumberOfEnemies(); goldPileIndex++){
        if(goldPileContainingOpenSpace->getGoldPiles()->getAt(goldPileIndex) == goldPile){
            return true;
        }
    }
    return false;
}

int Rules::calculateDamageGivenFromCharacterToCharacter(Character *attacker, Character *target){
    float damage = (100.0 / (100 + target->getDefensePoints())) * attacker->getAttackPoints();
    return (damage == (int) damage ? (int) damage : (int) damage + 1);
}

bool Rules::isCharacterAlive(Character *character){
    return character->getHealthPoints() > 0;
}
