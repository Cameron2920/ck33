#include "connector.h"

Connector::Connector():connectedOpenSpace1(0),connectedOpenSpace2(0){}

Connector::Connector(OpenSpace *connectedOpenSpace1, OpenSpace *connectedOpenSpace2):connectedOpenSpace1(connectedOpenSpace1), connectedOpenSpace2(connectedOpenSpace2){}

Connector::Connector(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter):Cell(rowCoordinate, columnCoordinate, terminalDisplayCharacter), connectedOpenSpace1(0), connectedOpenSpace2(0){}

OpenSpace* Connector::getConnectedOpenSpace1(){
    return connectedOpenSpace1;
}

void Connector::setConnectedOpenSpace1(OpenSpace *openSpace){
    this->connectedOpenSpace1 = openSpace;
}

OpenSpace* Connector::getConnectedOpenSpace2(){
    return connectedOpenSpace2;
}

void Connector::setConnectedOpenSpace2(OpenSpace *openSpace){
    this->connectedOpenSpace2 = openSpace;
}
