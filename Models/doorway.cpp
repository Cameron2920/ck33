#include "doorway.h"

Doorway::Doorway():Connector(){}

Doorway::Doorway(Chamber *chamber, Passageway *passageway):Connector(chamber, passageway){}

Doorway::Doorway(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter):Connector(rowCoordinate, columnCoordinate, terminalDisplayCharacter){}

Chamber* Doorway::getChamber(){
    return chamber;
}

Passageway* Doorway::getPassageway(){
    return passageway;
}

void Doorway::setChamber(Chamber *chamber){
    this->chamber = chamber;
}

void Doorway::setPassageway(Passageway *passageway){
    this->passageway = passageway;
}
