#include "gamecontroller.h"

void gameController(){
    Floor* floor = new Floor("non_standard_floor.txt");
    Rules* rules = new Rules;
    Initializer* initializer = new Initializer;
    PlayableCharacter* player = selectCharacter();
    initializer->intializeFloor(floor, 20, 10, 10, player);
    std::string input, direction;
    std::string action = "PC has spawned.";

    display(floor, player, action);
    while(std::cin >> input){
        action = "";
        if(input == "a"){
            std::cin >> direction;
            action += playerAttack(rules, player, direction, floor);
        }
        else if(input == "u"){
            std::cin >> direction;
            action += usePotion(rules, player, direction, floor);
        }
        else if(input == "r" || input == "q"){
            break;
        }
        else{
            action += movePlayer(floor, rules, player, input);
        }

        if(action != ""){
            action += simulateEnemyTurns(floor, rules, player);
            display(floor, player, action);
        }

        if(rules->hasPlayerLost(player)){
            break;
        }
        if(rules->hasPlayerCompletedFloor(player, floor)){
            player->incrementNumberOfCompletedFloors();
            if(rules->hasPlayerWon(player)){
               break;
            }
            initializer->reintializeFloor(floor, 20, 10, 10, player);
            display(floor, player, action);
        }
    }
    delete rules;
    delete floor;
    delete initializer;
    if(player){
        delete player;
    }

    if(input == "r"){
        gameController();
    }
}

std::string simulateEnemyTurns(Floor *floor, Rules *rules, PlayableCharacter* player){
    std::string action = "";
    ArtificialIntelligence* artificialIntelligence = new ArtificialIntelligence;
    ResizeableCellArray* enemyCells = floor->getCellsContainingEnemies();
    enemyCells->orderByCoordinates();

    for(int enemyIndex = 0; enemyIndex < enemyCells->getNumberOfElements(); enemyIndex++){
        if(dynamic_cast<EnemyCharacter*>(enemyCells->getAt(enemyIndex)->getEntity())){
            int playerHealthPointsBeforeTurn = player->getHealthPoints(), playerHealthPointsAfterTurn;
            EnemyCharacter* enemy = dynamic_cast<EnemyCharacter*>(enemyCells->getAt(enemyIndex)->getEntity());
            artificialIntelligence->simulateEnemyCharacter(enemy, player, rules, floor);
            playerHealthPointsAfterTurn = player->getHealthPoints();
            if(playerHealthPointsAfterTurn != playerHealthPointsBeforeTurn){
                action += " " + std::string(1, enemy->getTerminalDisplayCharacter()) + " deals " + INT_TO_STRING(playerHealthPointsBeforeTurn - playerHealthPointsAfterTurn) + " damage to PC.";
            }
        }
    }
    delete artificialIntelligence;
    return action;
}

bool isInputADirection(std::string input){
    return input == "no" || input == "so" || input == "ea"
            || input == "nw" || input == "ne" || input == "we"
            || input == "se" || input == "sw";
}

Cell* findCellByDirection(PlayableCharacter* player, std::string direction){
    Cell* playerCell = player->getCell();
    int playerCellRowCoordinate = playerCell->getRowCoordinate(), playerCellColumnCoordinate = playerCell->getColumnCoordinate();
    ResizeableCellArray* playerCellNeighbours = player->getCell()->getCellNeigbours();
    if(direction == "no"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate - 1, playerCellColumnCoordinate);
    }
    else if(direction == "so"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate + 1, playerCellColumnCoordinate);
    }
    else if(direction == "ea"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate, playerCellColumnCoordinate + 1);
    }
    else if(direction == "we"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate, playerCellColumnCoordinate - 1);
    }
    else if(direction == "ne"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate - 1, playerCellColumnCoordinate + 1);
    }
    else if(direction == "nw"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate - 1, playerCellColumnCoordinate - 1);
    }
    else if(direction == "se"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate + 1, playerCellColumnCoordinate + 1);
    }
    else if(direction == "sw"){
        return playerCellNeighbours->findByCoordinates(playerCellRowCoordinate + 1, playerCellColumnCoordinate - 1);
    }
    return 0;
}

void display(Floor *floor, PlayableCharacter *player, std::string action){
    std::cout << floor;
    std::cout << player;
    std::cout << "Action:" << action << std::endl;
}

PlayableCharacter* selectCharacter(){
    std::string race;
    PlayableCharacter* player;
    std::cout << "Select a race: ";
    while(race != "e" && race != "h" && race != "d" && race != "o"){
        std::cin >> race;
    }
    if(race == "e"){
        player = new Elf;
    }
    else if(race == "h"){
        player = new Human;
    }
    else if(race == "o"){
        player = new Orc;
    }
    else {
        player = new Dwarf;
    }
    player->setTerminalDisplayCharacter('@');
    return player;
}

std::string movePlayer(Floor* floor, Rules* rules, PlayableCharacter* player, std::string direction){
    Cell* newCell = findCellByDirection(player, direction);
    std::string action = " PC moved " + direction;

    if(newCell && rules->canPlayerMoveToCell(player, newCell, floor)){
        if(newCell->getEntity() && dynamic_cast<GoldPile*>(newCell->getEntity())){
            GoldPile* goldPile = dynamic_cast<GoldPile*>(newCell->getEntity());

            if(rules->canPlayerCollectGoldPile(player, goldPile, floor)){
                player->collectGoldPile(goldPile);
                action += "and collected a gold pile of value " + goldPile->getValue();
                Chamber* goldPileChamber = floor->findContainingChamber(newCell);
                if(goldPileChamber){
                    goldPileChamber->getGoldPiles()->remove(goldPile);
                }
            }
            else {
                return "";
            }
        }
        else if(newCell->getEntity() && dynamic_cast<Ladder*>(newCell->getEntity())){
            Ladder* ladder = dynamic_cast<Ladder*>(newCell->getEntity());
            if(ladder == floor->getLadder()){
                floor->setHasLadderBeenClimbed(true);
            }
        }
        player->moveToCell(newCell);
        return action + ".";
    }
    return "";
}

std::string playerAttack(Rules* rules, PlayableCharacter* player, std::string direction, Floor* floor){
    Cell* newCell = findCellByDirection(player, direction);
    std::string action = " PC attacked ";

    if(dynamic_cast<EnemyCharacter*>(newCell->getEntity())){
        EnemyCharacter* target = dynamic_cast<EnemyCharacter*>(newCell->getEntity());

        if(rules->canCharacterAttackCharacter(player, target)){
            player->attackCharacter(target, rules->calculateDamageGivenFromCharacterToCharacter(player, target));
            if(dynamic_cast<Merchant*>(target)){
                player->setHasAttackedMerchant(true);
            }
            action += std::string(1, target->getTerminalDisplayCharacter()) + " for " + INT_TO_STRING(rules->calculateDamageGivenFromCharacterToCharacter(player, target)) + " damage.";
            if(!rules->isCharacterAlive(target)){
                action += " RIP in peace " + std::string(1, target->getTerminalDisplayCharacter()) + ".";
                Chamber* chamber = floor->findContainingChamber(target->getCell());
                if(dynamic_cast<Dragon*>(target)){
                    Dragon* dragon = dynamic_cast<Dragon*>(target);
                    chamber->getGoldPiles()->add(dragon->getGoldPile());
                }
                else{
                    player->collectGoldPile(target->getGoldPile());
                }
                target->setGoldPile(0);
                if(chamber){
                    chamber->getEnemies()->remove(target);
                }
            }
            return action;
        }
    }
    return "";
}

std::string usePotion(Rules* rules, PlayableCharacter* player, std::string direction, Floor* floor){
    Cell* newCell = findCellByDirection(player, direction);
    std::string action = " PC used ";

    if(dynamic_cast<Potion*>(newCell->getEntity())){
        Potion* potion = dynamic_cast<Potion*>(newCell->getEntity());
        player->consumePotion(potion);
        newCell->setEntity(0);
        potion->setCell(0);
        Chamber* chamber = floor->findContainingChamber(newCell);
        if(chamber){
            chamber->getPotions()->pop(potion);
        }
        return action + std::string(1, potion->getTerminalDisplayCharacter()) + ".";
    }
    return "";
}
