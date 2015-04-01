#ifndef CONNECTOR_H
#define CONNECTOR_H
#include "cell.h"

#ifdef OPENSPACE_H
class OpenSpace;
#else
#include "OpenSpaces/openspace.h"
#endif

class Connector : public Cell {
public:
    Connector();
    virtual ~Connector();
    Connector(OpenSpace* connectedOpenSpace1, OpenSpace* connectedOpenSpace2);
    Connector(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter);
    void setConnectedOpenSpace1(OpenSpace* openSpace);
    OpenSpace* getConnectedOpenSpace1();
    void setConnectedOpenSpace2(OpenSpace* openSpace);
    OpenSpace* getConnectedOpenSpace2();
private:
    OpenSpace* connectedOpenSpace1;
    OpenSpace* connectedOpenSpace2;
};

#endif // CONNECTOR_H
