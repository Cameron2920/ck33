#include "chamber.h"

Chamber::Chamber(){
    doorways = new ResizeableArray<Doorway>;
    walls = new ResizeableArray<Wall>;
    enemies = new ResizeableArray<EnemyCharacter>;
    potions = new ResizeableArray<Potion>;
    goldPiles = new ResizeableArray<GoldPile>;
}

Chamber::~Chamber(){
    delete doorways;
    delete enemies;
    delete walls;
    delete potions;
    delete goldPiles;
}

void Chamber::addDoorway(Doorway *doorway){
    addConnector(doorway);
    doorways->add(doorway);
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
    enemies->append(chamber->getEnemies());
    potions->append(chamber->getPotions());
    goldPiles->append(chamber->getGoldPiles());
}

void Chamber::removeAllEnemies(){
    while(enemies->getNumberOfElements() > 0){
        enemies->remove(enemies->getAt(0));
    }
}

void Chamber::removeAllGoldPiles(){
    while(potions->getNumberOfElements() > 0){
        potions->remove(potions->getAt(0));
    }
}

void Chamber::removeAllPotions(){
    while(goldPiles->getNumberOfElements() > 0){
        goldPiles->remove(goldPiles->getAt(0));
    }
}

void Chamber::removeAllEntities(){
    removeAllEnemies();
    removeAllGoldPiles();
    removeAllPotions();
}


ResizeableArray<Connector>* Chamber::getConnectors(){
    return (ResizeableArray<Connector>*) doorways;
}

void Chamber::setConnectors(ResizeableArray<Connector>* connectors){
    OpenSpace::setConnectors(connectors);
    doorways = (ResizeableArray<Doorway>*) connectors;
}

