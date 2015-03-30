#include "chamber.h"

Chamber::Chamber(){
    setCells(new ResizeableCellArray);
    setUnoccupiedCells(new ResizeableCellArray);
    doorways = new ResizeableArray<Doorway>;
    setConnectors((ResizeableArray<Connector>*) doorways);
    walls = new ResizeableArray<Wall>;
    enemies = new ResizeableArray<EnemyCharacter>;
    potions = new ResizeableArray<Potion>;
    goldPiles = new ResizeableArray<GoldPile>;
}

void Chamber::addDoorway(Doorway *doorway){
    addConnector(doorway);
}

void Chamber::addWall(Wall *wall){
    addCell(wall);
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

ResizeableArray<Doorway>* Chamber::getDoorways(){
    return doorways;
}

ResizeableArray<Wall>* Chamber::getWalls(){
    return walls;
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

int Chamber::getNumberOfEnemies(){
    return enemies->getNumberOfElements();
}

void Chamber::appendChamber(Chamber* chamber){
    appendOpenSpace(chamber);
    doorways->append(chamber->getDoorways());
    walls->append(chamber->getWalls());
}
