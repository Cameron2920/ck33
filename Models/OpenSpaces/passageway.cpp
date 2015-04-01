#include "passageway.h"

Passageway::Passageway(){
    doorways = new ResizeableArray<Doorway>;
}

Passageway::~Passageway(){
    delete doorways;
}

ResizeableArray<Doorway>* Passageway::getDoorways(){
    return doorways;
}

void Passageway::appendPassageway(Passageway *passageway){
    appendOpenSpace(passageway);
    doorways->append(passageway->getDoorways());
}

ResizeableArray<Connector>* Passageway::getConnectors(){
    return (ResizeableArray<Connector>*) doorways;
}

void Passageway::setConnectors(ResizeableArray<Connector>* connectors){
    OpenSpace::setConnectors(connectors);
    doorways = (ResizeableArray<Doorway>*) connectors;
}
