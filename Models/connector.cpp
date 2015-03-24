#include "connector.h"

Connector::Connector(){}

Connector::Connector(OpenSpace *connectedOpenSpace1, OpenSpace *connectedOpenSpace2):connectedOpenSpace1(connectedOpenSpace1), connectedOpenSpace2(connectedOpenSpace2){}

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
