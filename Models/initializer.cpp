#include "initializer.h"

Initializer::Initializer(){}

void Initializer::intializeFloor(Floor *floor, int numberOfEnemies, int numberOfPotions, int numberOfGoldPiles, PlayableCharacter* player){
    initializeLadder(floor);
    initializePlayer(floor, player);
    initializeFloorEnemies(floor, numberOfEnemies);
    initializeFloorGoldPiles(floor, numberOfGoldPiles);
    initializeFloorPotions(floor, numberOfPotions);
}

void Initializer::initializeFloorEnemies(Floor *floor, int numberOfEnemies){
    int numberOfPlacedEnemies = 0;
    while(numberOfPlacedEnemies < numberOfEnemies){
        ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();

        if(availableChambers->getNumberOfElements() <= 0){
            break;
        }
        Chamber* chamber = selectRandomChamber(availableChambers);
        chamber->addEnemy(createRandomEnemyCharacter(), selectRandomCellFromChamber(chamber));
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
        chamber->addPotion(createRandomPotion(), selectRandomCellFromChamber(chamber));
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
        GoldPile* goldPile;
        int randomNumber = rand() % 8;
        if(randomNumber <= 0  && cell->getUnoccupiedCellNeigbours()->getNumberOfElements() > 0){
            Dragon* dragon = new Dragon;
            goldPile = new GoldPile(6);
            dragon->setGoldPile(goldPile);
            dragon->setTerminalDisplayCharacter('D');
            chamber->setCellEntity(cell->getUnoccupiedCellNeigbours()->getAt(rand() % cell->getUnoccupiedCellNeigbours()->getNumberOfElements()), dragon);
        }
        else if(randomNumber <= 3){
            goldPile = new GoldPile(2);
        }
        else{
            goldPile = new GoldPile(1);
        }
        goldPile->setTerminalDisplayCharacter('$');
        chamber->addGoldPile(goldPile, cell);
        numberOfPlacedGoldPiles++;
    }
}

void Initializer::initializeLadder(Floor *floor){
    Ladder* ladder = new Ladder;
    ladder->setTerminalDisplayCharacter('\\');
    ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();
    floor->addLadder(selectRandomCellFromChamber(selectRandomChamber(availableChambers)), ladder);
}

void Initializer::initializePlayer(Floor *floor, PlayableCharacter *player){
    ResizeableArray<Chamber>* availableChambers = floor->getUnfilledChambers();
    Chamber* ladderChamber = floor->findContainingChamber(floor->getLadder()->getCell()), *selectedChamber;

    if(availableChambers->getNumberOfElements() == 1){
        selectedChamber = availableChambers->getAt(0);
    }
    else{
        Chamber* randomChamber = selectRandomChamber(availableChambers);
        while(randomChamber == ladderChamber){
            randomChamber = selectRandomChamber(availableChambers);
        }
        selectedChamber = randomChamber;
    }
    selectedChamber->setCellEntity(selectRandomCellFromChamber(selectedChamber), player);
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
        enemyCharacter = new Phoenix;
        enemyCharacter->setTerminalDisplayCharacter('X');
    }
    else{
        enemyCharacter = new Merchant;
        enemyCharacter->setTerminalDisplayCharacter('M');
    }
    return enemyCharacter;
}

Potion* Initializer::createRandomPotion(){
    Potion* potion;
    int randomNumber = rand() % 6;
    if(randomNumber <= 0){
        potion = new Potion(Potion::HealthPoints, 10);
    }
    else if(randomNumber <= 1){
        potion = new Potion(Potion::HealthPoints, -10);
    }
    else if(randomNumber <= 2){
        potion = new Potion(Potion::AttackPoints, 5);
    }
    else if(randomNumber <= 3){
        potion = new Potion(Potion::AttackPoints, -5);
    }
    else if(randomNumber <= 4){
        potion = new Potion(Potion::DefensePoints, 5);
    }
    else{
        potion = new Potion(Potion::DefensePoints, -5);
    }
    potion->setTerminalDisplayCharacter('P');
    return potion;
}
