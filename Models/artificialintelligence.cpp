#include "artificialintelligence.h"

ArtificialIntelligence::ArtificialIntelligence(){}

void ArtificialIntelligence::simulateEnemyCharacter(EnemyCharacter* enemyCharacter, MoveableCharacter* targetCharacter, Rules* rules, Floor* floor){
    if(rules->canCharacterAttackCharacter(enemyCharacter, targetCharacter)){
        enemyCharacter->attackCharacter(targetCharacter, rules->calculateDamageGivenFromCharacterToCharacter(enemyCharacter, targetCharacter));
    }
    else{
        simulateEnemyCharacterMove(enemyCharacter, rules, floor);
    }
}

void ArtificialIntelligence::simulateEnemyCharacterMove(EnemyCharacter *enemyCharacter, Rules* rules, Floor* floor){
    Cell* enemyCharacterCell = enemyCharacter->getCell();
    ResizeableCellArray* unoccupiedNeighbourCells = enemyCharacterCell->getUnoccupiedCellNeigbours();

    if(unoccupiedNeighbourCells->getNumberOfElements() > 0){
        Cell* newCell = unoccupiedNeighbourCells->getAt(rand() % unoccupiedNeighbourCells->getNumberOfElements());
        if(rules->canEnemyPlayerMoveToCell(enemyCharacter, newCell, floor)){
            enemyCharacter->moveToCell(newCell);
        }
    }
}
