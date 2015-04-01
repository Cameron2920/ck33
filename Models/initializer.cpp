#include "initializer.h"

Initializer::Initializer(){}

void Initializer::reintializeFloor(Floor *floor, int numberOfEnemies, int numberOfPotions, int numberOfGoldPiles, PlayableCharacter* player){
    for(int chamberIndex = 0; chamberIndex < floor->getChambers()->getNumberOfElements(); chamberIndex++){
        floor->getChambers()->getAt(chamberIndex)->removeAllEntities();
    }
    intializeFloor(floor, numberOfEnemies, numberOfPotions, numberOfGoldPiles, player);
}

void Initializer::intializeFloor(Floor *floor, int numberOfEnemies, int numberOfPotions, int numberOfGoldPiles, PlayableCharacter* player){
    floor->setPlayer(player);
    if(!player->getCell()){
        initializePlayer(floor, player);
    }
    initializeLadder(floor, player);
    initializeFloorEnemies(floor, numberOfEnemies);
    initializeFloorGoldPiles(floor, numberOfGoldPiles);
    initializeFloorPotions(floor, numberOfPotions);
    floor->setHasLadderBeenClimbed(false);
}

void Initializer::initializeFloorEnemies(Floor *floor, int numberOfEnemies){
    int numberOfPlacedEnemies = 0;
    while(numberOfPlacedEnemies < numberOfEnemies){
        ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();

        if(availableChambers->getNumberOfElements() <= 0){
            break;
        }
        Chamber* chamber = selectRandomChamber(availableChambers);
        Cell* cell = selectRandomCellFromChamber(chamber);

        if(dynamic_cast<Connector*>(cell)){
            continue;
        }
        EnemyCharacter* enemy = createRandomEnemyCharacter();
        chamber->addEnemy(enemy, cell);
        numberOfPlacedEnemies++;
    }
}

void Initializer::initializeFloorPotions(Floor *floor, int numberOfPotions){
    int numberOfPlacedPotions = 0;
    while(numberOfPlacedPotions < numberOfPotions){
        ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();

        if(availableChambers->getNumberOfElements() <= 0){
            break;
        }
        Chamber* chamber = selectRandomChamber(availableChambers);
        Cell* cell = selectRandomCellFromChamber(chamber);

        if(dynamic_cast<Connector*>(cell)){
            continue;
        }

        chamber->addPotion(createRandomPotion(), cell);
        numberOfPlacedPotions++;
    }
}

void Initializer::initializeFloorGoldPiles(Floor *floor, int numberOfGoldPiles){
    int numberOfPlacedGoldPiles = 0;
    while(numberOfPlacedGoldPiles < numberOfGoldPiles){
        ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();

        if(availableChambers->getNumberOfElements() <= 0){
            break;
        }
        Chamber* chamber = selectRandomChamber(availableChambers);
        Cell* cell = selectRandomCellFromChamber(chamber);

        if(dynamic_cast<Connector*>(cell)){
            continue;
        }

        GoldPile* goldPile;
        int randomNumber = rand() % 8;
        if(randomNumber <= 0  && cell->getUnoccupiedCellNeigbours()->getNumberOfElements() > 0){
            Dragon* dragon = new Dragon;
            goldPile = new GoldPile(6);
            cell->setEntity(goldPile);
            goldPile->setCell(cell);
            goldPile->setTerminalDisplayCharacter('9');
            dragon->setGoldPile(goldPile);
            dragon->setTerminalDisplayCharacter('D');
            chamber->addEnemy(dragon, cell->getUnoccupiedCellNeigbours()->getAt(rand() % cell->getUnoccupiedCellNeigbours()->getNumberOfElements()));
        }
        else if(randomNumber <= 3){
            goldPile = new GoldPile(2);
            chamber->addGoldPile(goldPile, cell);
            goldPile->setTerminalDisplayCharacter('7');
        }
        else{
            goldPile = new GoldPile(1);
            chamber->addGoldPile(goldPile, cell);
            goldPile->setTerminalDisplayCharacter('6');
        }
        numberOfPlacedGoldPiles++;
    }
}

void Initializer::initializeLadder(Floor *floor, PlayableCharacter* player){
    Ladder* ladder = new Ladder;
    ladder->setTerminalDisplayCharacter('\\');
    ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();
    Chamber* playerChamber = floor->findContainingChamber(player->getCell());
    Chamber* selectedChamber;

    if(availableChambers->getNumberOfElements() == 1){
        selectedChamber = availableChambers->getAt(0);
    }
    else{
        Chamber* randomChamber = selectRandomChamber(availableChambers);
        while(randomChamber == playerChamber){
            randomChamber = selectRandomChamber(availableChambers);
        }
        selectedChamber = randomChamber;
    }
    Cell* cell = selectRandomCellFromChamber(selectedChamber);
    while(dynamic_cast<Connector*>(cell)){
        cell = selectRandomCellFromChamber(selectedChamber);
    }
    floor->addLadder(cell, ladder);
}

void Initializer::initializePlayer(Floor *floor, PlayableCharacter *player){
    ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();
    Chamber* selectedChamber = selectRandomChamber(availableChambers);
    Cell* cell = selectRandomCellFromChamber(selectedChamber);
    while(dynamic_cast<Connector*>(cell)){
        cell = selectRandomCellFromChamber(selectedChamber);
    }
    selectedChamber->setCellEntity(cell, player);
}

Chamber* Initializer::selectRandomChamber(ResizeableArray<Chamber> *availableChambers){
    return availableChambers->getAt(rand() % availableChambers->getNumberOfElements());
}

Cell* Initializer::selectRandomCellFromChamber(Chamber* chamber){
    return chamber->getUnoccupiedCells()->getAt(rand() % chamber->getUnoccupiedCells()->getNumberOfElements());
}

EnemyCharacter* Initializer::createRandomEnemyCharacter(){
    EnemyCharacter* enemyCharacter;
    int randomNumber = rand() % 18;

    if(randomNumber <= 3){
        enemyCharacter = new Werewolf;
        enemyCharacter->setTerminalDisplayCharacter('W');
    }
    else if(randomNumber <= 6){
        enemyCharacter = new Vampire;
        enemyCharacter->setTerminalDisplayCharacter('V');
    }
    else if(randomNumber <= 11){
        enemyCharacter = new Goblin;
        enemyCharacter->setTerminalDisplayCharacter('G');
    }
    else if(randomNumber <= 13){
        enemyCharacter = new Troll;
        enemyCharacter->setTerminalDisplayCharacter('T');
    }
    else if(randomNumber <= 15){
        enemyCharacter = new Merchant;
        enemyCharacter->setTerminalDisplayCharacter('M');
    }
    else{
        enemyCharacter = new Phoenix;
        enemyCharacter->setTerminalDisplayCharacter('X');
    }
    return enemyCharacter;
}

Potion* Initializer::createRandomPotion(){
    Potion* potion;
    int randomNumber = rand() % 6;
    if(randomNumber <= 0){
        potion = new Potion(Potion::HealthPoints, 10);
        potion->setTerminalDisplayCharacter('0');
    }
    else if(randomNumber <= 1){
        potion = new Potion(Potion::HealthPoints, -10);
        potion->setTerminalDisplayCharacter('3');
    }
    else if(randomNumber <= 2){
        potion = new Potion(Potion::AttackPoints, 5);
        potion->setTerminalDisplayCharacter('1');
    }
    else if(randomNumber <= 3){
        potion = new Potion(Potion::AttackPoints, -5);
        potion->setTerminalDisplayCharacter('4');
    }
    else if(randomNumber <= 4){
        potion = new Potion(Potion::DefensePoints, 5);
        potion->setTerminalDisplayCharacter('2');
    }
    else{
        potion = new Potion(Potion::DefensePoints, -5);
        potion->setTerminalDisplayCharacter('5');
    }
    return potion;
}
