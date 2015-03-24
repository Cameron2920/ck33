#include "doorway.h"

Doorway::Doorway(){}

Doorway::Doorway(Chamber *chamber, Passageway *passageway):Connector(chamber, passageway){}

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
