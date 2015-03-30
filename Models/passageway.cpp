#include "passageway.h"

Passageway::Passageway():OpenSpace(){
    doorways = new ResizeableArray<Doorway>;
    setConnectors((ResizeableArray<Connector>*) doorways);
}

ResizeableArray<Doorway>* Passageway::getDoorways(){
    return doorways;
}

void Passageway::appendPassageway(Passageway *passageway){
    appendOpenSpace(passageway);
    doorways->append(passageway->getDoorways());
}
