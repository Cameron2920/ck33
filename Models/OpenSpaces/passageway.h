#ifndef PASSAGEWAY_H
#define PASSAGEWAY_H

#include "openspace.h"

#ifdef DOORWAY_H
class Doorway;
#else
#include "Cells/doorway.h"
#endif

class Passageway : public OpenSpace {
public:
    Passageway();
    virtual ~Passageway();
    void appendPassageway(Passageway* passageway);
    ResizeableArray<Doorway>* getDoorways();
    virtual ResizeableArray<Connector>* getConnectors();
    virtual void setConnectors(ResizeableArray<Connector>* connectors);
private:
    ResizeableArray<Doorway>* doorways;
};

#endif // PASSAGEWAY_H
