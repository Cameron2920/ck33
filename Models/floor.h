#ifndef FLOOR_H
#define FLOOR_H
#include "OpenSpaces/chamber.h"
#include "OpenSpaces/passageway.h"
#include "Entities/ladder.h"
#include "Entities/Characters/MoveableCharacters/PlayableCharacters/playablecharacter.h"
#include <iostream>
#include <sstream>
#include <fstream>

class Floor {
public:
    Floor();
    ~Floor();
    Floor(std::string filename);
    OpenSpace* findContainingOpenSpace(Cell* cell);
    Chamber* findContainingChamber(Cell* cell);
    Passageway* findContainingPassageway(Cell* cell);
    Ladder* getLadder();
    void addLadder(Cell* cell, Ladder* ladder);
    void addCellToChamber(Cell* cell);
    void addCellToPassageway(Cell* cell);
    void addDoorway(Doorway* doorway);
    int maxRowCoordinate();
    int maxColumnCoordinate();
    Cell* findCellByCoordinates(int rowCoordinate, int columnCoordinate);
    ResizeableArray<Chamber>* getUnfilledChambers();
    ResizeableCellArray* getCellsContainingEnemies();
    ResizeableArray<Chamber>* getChambers();
    void mergeConnectedChambers();
    void mergeConnectedPassageWays();
    void setHasLadderBeenClimbed(bool hasLadderBeenClimbed);
    bool getHasLadderBeenClimbed();
    void setPlayer(PlayableCharacter* player);
    PlayableCharacter* getPlayer();
private:
    PlayableCharacter* player;
    bool hasLadderBeenClimbed;
    ResizeableCellArray* enemyCells;
    ResizeableArray<Chamber>* chambers;
    ResizeableArray<Chamber>* unfilledChambers;
    ResizeableArray<Passageway>* passageways;
    ResizeableArray<Potion>* discoveredPotions;
    Ladder* ladder;
    Chamber* findConnectedChamber(Cell* cell);
    Passageway* findConnectedPassageway(Cell* cell);

    friend std::ostream& operator<<(std::ostream& os, Floor* floor);
};

#endif // FLOOR_H
