#ifndef FLOOR_H
#define FLOOR_H
#include "chamber.h"
#include "passageway.h"
#include "ladder.h"
#include <iostream>
#include <sstream>
#include <fstream>

class Floor {
public:
    Floor();
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
    void mergeConnectedChambers();
    void mergeConnectedPassageWays();
private:
    ResizeableCellArray* enemyCells;
    ResizeableArray<Chamber>* chambers;
    ResizeableArray<Chamber>* unfilledChambers;
    ResizeableArray<Passageway>* passageways;
    Ladder* ladder;
    Chamber* findConnectedChamber(Cell* cell);
    Passageway* findConnectedPassageway(Cell* cell);

    friend std::ostream& operator<<(std::ostream& os, Floor* floor);
};

#endif // FLOOR_H
