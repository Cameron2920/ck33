#ifndef FLOOR_H
#define FLOOR_H
#include "chamber.h"
#include "passageway.h"
#include "ladder.h"
#include <iostream>
#include <fstream>

class Floor {
public:
    Floor();
    OpenSpace* findContainingOpenSpace(Cell* cell);
    Chamber* findContainingChamber(Cell* cell);
//    Passageway* findContainingPassageway(Cell* cell);
    Ladder* getLadder();
    void setLadder(Ladder* ladder);
private:
    Chamber** chambers;
    int numberOfChambers;
    int chambersCapacity;
//    Passageway** passageways;
    int numberOfPassageways;
    int passagewaysCapacity;
    Ladder* ladder;

    friend std::ostream& operator<<(std::ostream& os, Floor* floor);
};

#endif // FLOOR_H
