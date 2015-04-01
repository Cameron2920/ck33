#include "doorway.h"

Doorway::Doorway():Connector(), chamber(0), passageway(0){
    setConnectedOpenSpace1(0);
    setConnectedOpenSpace2(0);
}

Doorway::Doorway(Chamber *chamber, Passageway *passageway):Connector(chamber, passageway){}

Doorway::Doorway(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter):Connector(rowCoordinate, columnCoordinate, terminalDisplayCharacter), chamber(0), passageway(0){
    setConnectedOpenSpace1(0);
    setConnectedOpenSpace2(0);
}

Chamber* Doorway::getChamber(){
    return chamber;
}

Passageway* Doorway::getPassageway(){
    return passageway;
}

void Doorway::setChamber(Chamber *chamber){
    setConnectedOpenSpace1(chamber);
    this->chamber = chamber;
}

void Doorway::setPassageway(Passageway *passageway){
    setConnectedOpenSpace2(passageway);
    this->passageway = passageway;
}
