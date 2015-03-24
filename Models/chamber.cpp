#include "chamber.h"

Chamber::Chamber(){
    connectors = doorways;
}

void Chamber::addDoorway(Doorway *doorway){
    connectors->add(doorway);
}

void Chamber::addWall(Wall *wall){
    cells->add(wall);
    walls->add(wall);
}

ResizeableArray<EnemyCharacter>* Chamber::getEnemies(){
    return enemies;
}

ResizeableArray<Potion>* Chamber::getPotions(){
    return potions;
}

ResizeableArray<GoldPile>* Chamber::getGoldPiles(){
    return goldPiles;
}

void Chamber::addEnemy(EnemyCharacter* enemy, Cell* cell){
    enemies->add(enemy);
    cell->setEntity(enemy);
    enemy->setCell(cell);
}

void Chamber::addPotion(Potion* potion, Cell* cell){
    potions->add(potion);
    cell->setEntity(potion);
    potion->setCell(cell);
}

void Chamber::addGoldPile(GoldPile* goldPile, Cell* cell){
    goldPiles->add(goldPile);
    cell->setEntity(goldPile);
    goldPile->setCell(cell);
}
