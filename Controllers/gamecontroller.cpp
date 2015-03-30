#include "gamecontroller.h"

void gameController(){
    Floor* floor = new Floor("standard_floor.txt");
    Rules* rules = new Rules;
    Initializer* initializer = new Initializer;
    PlayableCharacter* player = new Human;
    player->setTerminalDisplayCharacter('@');
    initializer->intializeFloor(floor, 20, 10, 10, player);
    std::string input;

    display(floor, player);
    while(std::cin >> input){
        Cell* newCell = findCellByDirection(player, input);

        if(newCell && rules->canPlayerMoveToCell(player, newCell, floor)){
            player->moveToCell(newCell);
        }
        simulateEnemyTurns(floor, rules, player);
        display(floor, player);
    }
}

void simulateEnemyTurns(Floor *floor, Rules *rules, PlayableCharacter* player){
    ArtificialIntelligence* artificialIntelligence = new ArtificialIntelligence;
    ResizeableCellArray* enemyCells = floor->getCellsContainingEnemies();
    enemyCells->orderByCoordinates();

    for(int enemyIndex = 0; enemyIndex < enemyCells->getNumberOfElements(); enemyIndex++){
        artificialIntelligence->simulateEnemyCharacter(dynamic_cast<EnemyCharacter*>(enemyCells->getAt(enemyIndex)->getEntity()), player, rules, floor);
    }
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

void display(Floor *floor, PlayableCharacter *player){
    std::cout << floor;
    std::cout << player;
    std::cout << "Action: ";
}
