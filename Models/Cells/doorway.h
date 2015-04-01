#ifndef DOORWAY_H
#define DOORWAY_H
#include "connector.h"

#ifdef CHAMBER_H
class Chamber;
#else
#include "OpenSpaces/chamber.h"
#endif

#ifdef PASSAGEWAY_H
class Passageway;
#else
#include "OpenSpaces/passageway.h"
#endif

class Doorway : public Connector {
public:
    Doorway();
    Doorway(Chamber* chamber, Passageway* passageway);
    Doorway(int rowCoordinate, int columnCoordinate, char terminalDisplayCharacter);
    void setChamber(Chamber* chamber);
    Chamber* getChamber();
    void setPassageway(Passageway* passageway);
    Passageway* getPassageway();
private:
    Chamber* chamber;
    Passageway* passageway;
};

#endif // DOORWAY_H
