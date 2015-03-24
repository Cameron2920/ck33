#include "floor.h"

Floor::Floor():chambersCapacity(5), numberOfChambers(0), passagewaysCapacity(5), numberOfPassageways(1){}

Chamber* Floor::findContainingChamber(Cell *cell){
    for(int chamberIndex = 0; chamberIndex < numberOfPassageways; chamberIndex++){
        if(chambers[chamberIndex]->isContainingCell(cell)){
            return chambers[chamberIndex];
        }
    }
    return 0;
}

//Passageway* Floor::findContainingPassageway(Cell *cell){
//    for(int passagewayIndex = 0; passagewayIndex < numberOfPassageways; passagewayIndex++){
//        if(passageways[passagewayIndex]->isContainingCell(cell)){
//            return passageways[passagewayIndex];
//        }
//    }
//    return 0;
//}

OpenSpace* Floor::findContainingOpenSpace(Cell *cell){
    OpenSpace* openSpace = findContainingChamber(cell);
    if(!openSpace){
//        openSpace = findContainingPassageway(cell);
    }
    return openSpace;
}
