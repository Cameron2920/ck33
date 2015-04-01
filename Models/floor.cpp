#include "floor.h"

Floor::Floor(){
    chambers = new ResizeableArray<Chamber>;
    unfilledChambers = new ResizeableArray<Chamber>;
    passageways = new ResizeableArray<Passageway>;
    enemyCells = new ResizeableCellArray;
}

Floor::~Floor(){
    ResizeableCellArray* allCells = new ResizeableCellArray;
    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        allCells->merge(chambers->getAt(chamberIndex)->getCells());
        chambers->getAt(chamberIndex)->removeAllEntities();
        delete chambers->getAt(chamberIndex);
    }
    for(int passagewayIndex = 0; passagewayIndex < passageways->getNumberOfElements(); passagewayIndex++){
        allCells->merge(passageways->getAt(passagewayIndex)->getCells());
        delete passageways->getAt(passagewayIndex);
    }

    for(int allCellsIndex = 0; allCellsIndex < allCells->getNumberOfElements(); allCellsIndex++){
        delete allCells->getAt(allCellsIndex);
    }


    delete allCells;
    delete ladder;
    delete passageways;
    delete chambers;
    delete unfilledChambers;
    delete enemyCells;
}

Floor::Floor(std::string filename){
    chambers = new ResizeableArray<Chamber>;
    unfilledChambers = new ResizeableArray<Chamber>;
    passageways = new ResizeableArray<Passageway>;
    enemyCells = new ResizeableCellArray;

    std::ifstream inputFile(filename.c_str());
    int rowCoordinate = 0, columnCoordinate;
    char currentCharacter;

    while(!inputFile.eof() && !inputFile.fail()){
        int currentCharacterIndex = 0;
        std::string currentLineString;
        getline(inputFile, currentLineString);
        columnCoordinate = 0;
        while(currentCharacterIndex < currentLineString.length()){
            currentCharacter = currentLineString.at(currentCharacterIndex);
            switch(currentCharacter){
            case '|':
                addCellToChamber(new Wall(rowCoordinate, columnCoordinate, currentCharacter));
                break;
            case '-':
                addCellToChamber(new Wall(rowCoordinate, columnCoordinate, currentCharacter));
                break;
            case '.':
                addCellToChamber(new Cell(rowCoordinate, columnCoordinate, currentCharacter));
                break;
            case '#':
                addCellToPassageway(new Cell(rowCoordinate, columnCoordinate, currentCharacter));
                break;
            case '+':
                addDoorway(new Doorway(rowCoordinate, columnCoordinate, currentCharacter));
                break;
            }
            columnCoordinate++;
            currentCharacterIndex++;
        }
        rowCoordinate++;
    }
    mergeConnectedChambers();
    mergeConnectedPassageWays();
}

Chamber* Floor::findContainingChamber(Cell *cell){
    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        if(chambers->getAt(chamberIndex)->isContainingCell(cell)){
            return chambers->getAt(chamberIndex);
        }
    }
    return 0;
}

Passageway* Floor::findContainingPassageway(Cell *cell){
    for(int passagewayIndex = 0; passagewayIndex < passageways->getNumberOfElements(); passagewayIndex++){
        if(passageways->getAt(passagewayIndex)->isContainingCell(cell)){
            return passageways->getAt(passagewayIndex);
        }
    }
    return 0;
}

OpenSpace* Floor::findContainingOpenSpace(Cell *cell){
    OpenSpace* openSpace = findContainingChamber(cell);
    if(!openSpace){
        openSpace = findContainingPassageway(cell);
    }
    return openSpace;
}

Chamber* Floor::findConnectedChamber(Cell *cell){
    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        if(chambers->getAt(chamberIndex)->isCellConnected(cell)){
            return chambers->getAt(chamberIndex);
        }
    }
    return 0;
}

Passageway* Floor::findConnectedPassageway(Cell* cell){
    for(int passagewayIndex = 0; passagewayIndex < passageways->getNumberOfElements(); passagewayIndex++){
        if(passageways->getAt(passagewayIndex)->isCellConnected(cell)){
            return passageways->getAt(passagewayIndex);
        }
    }
    return 0;
}

void Floor::addCellToChamber(Cell* cell){
    Chamber* chamber = findConnectedChamber(cell);

    if(!chamber){
        chamber = new Chamber;
        chambers->add(chamber);
    }

    if(dynamic_cast<Wall*>(cell)){
        chamber->addWall(dynamic_cast<Wall*>(cell));
    }
    else{
        chamber->addCell(cell);
    }
}

void Floor::addCellToPassageway(Cell* cell){
    Passageway* passageway = findConnectedPassageway(cell);
    if(passageway){
        passageway->addCell(cell);
    }
    else{
        Passageway* newPassageway = new Passageway;
        passageways->add(newPassageway);
        newPassageway->addCell(cell);
    }
}

void Floor::addDoorway(Doorway* doorway){
    Passageway* passageway = findConnectedPassageway(doorway);
    if(passageway){
        passageway->addConnector(doorway);
        doorway->setPassageway(passageway);
    }
    else{
        Passageway* newPassageway = new Passageway;
        passageways->add(newPassageway);
        newPassageway->addConnector(doorway);
        doorway->setPassageway(newPassageway);
    }

    Chamber* chamber = findConnectedChamber(doorway);
    if(chamber){
        chamber->addDoorway(doorway);
        doorway->setChamber(chamber);
    }
    else{
        Chamber* newChamber = new Chamber;
        chambers->add(newChamber);
        newChamber->addDoorway(doorway);
        doorway->setChamber(newChamber);
    }
}

int Floor::maxColumnCoordinate(){
    int maxCoordinate = 0;

    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        int chamberMaxColumnCoordinate = chambers->getAt(chamberIndex)->maxColumnCoordinate();
        maxCoordinate = (chamberMaxColumnCoordinate > maxCoordinate ? chamberMaxColumnCoordinate : maxCoordinate);
    }
    for(int passagewayIndex = 0; passagewayIndex < passageways->getNumberOfElements(); passagewayIndex++){
        int passagewaysMaxColumnCoordinate = passageways->getAt(passagewayIndex)->maxColumnCoordinate();
        maxCoordinate = (passagewaysMaxColumnCoordinate > maxCoordinate ? passagewaysMaxColumnCoordinate : maxCoordinate);
    }
    return maxCoordinate;
}

int Floor::maxRowCoordinate(){
    int maxCoordinate = 0;

    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        int chamberMaxRowCoordinate = chambers->getAt(chamberIndex)->maxRowCoordinate();
        maxCoordinate = (chamberMaxRowCoordinate > maxCoordinate ? chamberMaxRowCoordinate : maxCoordinate);
    }
    for(int passagewayIndex = 0; passagewayIndex < passageways->getNumberOfElements(); passagewayIndex++){
        int passagewaysMaxRowCoordinate = passageways->getAt(passagewayIndex)->maxRowCoordinate();
        maxCoordinate = (passagewaysMaxRowCoordinate > maxCoordinate ? passagewaysMaxRowCoordinate : maxCoordinate);
    }
    return maxCoordinate;
}

Cell* Floor::findCellByCoordinates(int rowCoordinate, int columnCoordinate){
    Cell* cell = 0;
    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        cell = chambers->getAt(chamberIndex)->findCellByCoordinates(rowCoordinate, columnCoordinate);
        if(cell){
            return cell;
        }
    }
    for(int passagewaysIndex = 0; passagewaysIndex < passageways->getNumberOfElements(); passagewaysIndex++){
        cell = passageways->getAt(passagewaysIndex)->findCellByCoordinates(rowCoordinate, columnCoordinate);
        if(cell){
            return cell;
        }
    }
    return 0;
}

std::ostream& operator<<(std::ostream& os, Floor* floor){
    int currentRowCoordinate = 0, currentColumnCoordinate = 0;
    int maxColumnCoordinate = floor->maxColumnCoordinate(), maxRowCoordinate = floor->maxRowCoordinate();

    os << "|";
    for(int index = 0; index <= maxColumnCoordinate + 1; index++){
        os << "-";
    }
    os << "|" << std::endl;

    while(currentRowCoordinate <= maxRowCoordinate){
        os << "|";
        while(currentColumnCoordinate <= maxColumnCoordinate){
            Cell* cell = floor->findCellByCoordinates(currentRowCoordinate, currentColumnCoordinate);
            if(cell){
                Potion* potion = dynamic_cast<Potion*>(cell->getEntity());
                if(potion && !floor->getPlayer()->hasDiscoveredPotion(potion)){
                    os << "P";
                }
                else{
                    os << cell;
                }
            }
            else{
                os << " ";
            }
            currentColumnCoordinate++;
        }
        os << " |" << std::endl;
        currentColumnCoordinate = 0;
        currentRowCoordinate++;
    }
    os << "|";
    for(int index = 0; index <= maxColumnCoordinate + 1; index++){
        os << "-";
    }
    os << "|" << std::endl;
    return os;
}

Ladder* Floor::getLadder(){
    return ladder;
}

void Floor::addLadder(Cell* cell, Ladder *ladder){
    this->ladder = ladder;
    Chamber* chamber = findContainingChamber(cell);
    chamber->setCellEntity(cell, ladder);
}

ResizeableArray<Chamber>* Floor::getUnfilledChambers(){
    unfilledChambers->popAll();
    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        if(chambers->getAt(chamberIndex)->getUnoccupiedCells()->getNumberOfElements() > 0){
            unfilledChambers->add(chambers->getAt(chamberIndex));
        }
    }
    return unfilledChambers;
}

ResizeableCellArray* Floor::getCellsContainingEnemies(){
    enemyCells->popAll();
    for(int chamberIndex = 0; chamberIndex < chambers->getNumberOfElements(); chamberIndex++){
        ResizeableArray<EnemyCharacter>* chamberEnemies = chambers->getAt(chamberIndex)->getEnemies();

        for(int enemyIndex = 0; enemyIndex < chamberEnemies->getNumberOfElements(); enemyIndex++){
            enemyCells->add(chamberEnemies->getAt(enemyIndex)->getCell());
        }
    }
    return enemyCells;
}

void Floor::mergeConnectedChambers(){
    int chamberIndex1 = 0, chamberIndex2 = 0;

    while(chamberIndex1 < chambers->getNumberOfElements()){
        chamberIndex2 = 0;
        while(chamberIndex2 < chambers->getNumberOfElements() && chamberIndex1 < chambers->getNumberOfElements()){
            if(chamberIndex1 != chamberIndex2 && chambers->getAt(chamberIndex1)->isOpenSpaceConnected(chambers->getAt(chamberIndex2))){
                chambers->getAt(chamberIndex1)->appendChamber(chambers->getAt(chamberIndex2));
                chambers->remove(chambers->getAt(chamberIndex2));
            }
            else{
                chamberIndex2++;
            }
        }
        chamberIndex1++;
    }
}

void Floor::mergeConnectedPassageWays(){
    int passagewayIndex1 = 0, passagewayIndex2 = 0;

    while(passagewayIndex1 < passageways->getNumberOfElements()){
        passagewayIndex2 = 0;
        while(passagewayIndex2 < passageways->getNumberOfElements() && passagewayIndex1 < passageways->getNumberOfElements()){
            if(passagewayIndex2 != passagewayIndex1 && passageways->getAt(passagewayIndex1)->isOpenSpaceConnected(passageways->getAt(passagewayIndex2))){
                passageways->getAt(passagewayIndex1)->appendPassageway(passageways->getAt(passagewayIndex2));
                passageways->remove(passageways->getAt(passagewayIndex2));
            }
            else{
                passagewayIndex2++;
            }
        }
        passagewayIndex1++;
    }
}

bool Floor::getHasLadderBeenClimbed(){
    return hasLadderBeenClimbed;
}

void Floor::setHasLadderBeenClimbed(bool hasLadderBeenClimbed){
    this->hasLadderBeenClimbed = hasLadderBeenClimbed;
}

PlayableCharacter* Floor::getPlayer(){
    return player;
}

void Floor::setPlayer(PlayableCharacter *player){
    this->player = player;
}

ResizeableArray<Chamber>* Floor::getChambers(){
    return chambers;
}
