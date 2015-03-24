#include "artificialintelligence.h"

ArtificialIntelligence::ArtificialIntelligence(){}

void ArtificialIntelligence::simulateEnemyCharacter(MoveableCharacter* enemyCharacter, MoveableCharacter* targetCharacter, Rules* rules, Floor* floor){
    if(rules->canCharacterAttackCharacter(enemyCharacter, targetCharacter)){
        enemyCharacter->attackCharacter(targetCharacter, rules->calculateDamageGivenFromCharacterToCharacter(enemyCharacter, targetCharacter));
    }
    else{
        simulateEnemyCharacterMove(enemyCharacter, rules, floor);
    }
}

void ArtificialIntelligence::simulateEnemyCharacterMove(MoveableCharacter *enemyCharacter, Rules* rules, Floor* floor){
    int numberOfAvailableNeighbourCells = 0;
    Cell* enemyCharacterCell = enemyCharacter->getCell();
    Cell** availableNeighbourCells = new Cell*[MAX_NUMBER_OF_CELL_NEIGHBOURS];

    for(int neighbourCellIndex = 0; neighbourCellIndex < enemyCharacterCell->getNumberOfNeighbours(); neighbourCellIndex++){
        Cell* neighbourCell = enemyCharacterCell->getCellNeigbourAt(neighbourCellIndex);

        if(rules->canEnemyPlayerMoveToCell(enemyCharacter, neighbourCell, floor)){
            availableNeighbourCells[numberOfAvailableNeighbourCells] = neighbourCell;
            numberOfAvailableNeighbourCells++;
        }
    }

    if(numberOfAvailableNeighbourCells > 0){
        enemyCharacter->moveToCell(availableNeighbourCells[rand() % numberOfAvailableNeighbourCells]);
    }
    delete [] availableNeighbourCells;
}
