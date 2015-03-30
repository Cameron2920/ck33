#ifndef PASSAGEWAY_H
#define PASSAGEWAY_H

#include "openspace.h"

#ifdef DOORWAY_H
class Doorway;
#else
#include "doorway.h"
#endif

class Passageway : public OpenSpace {
public:
    Passageway();
    void appendPassageway(Passageway* passageway);
    ResizeableArray<Doorway>* getDoorways();
private:
    ResizeableArray<Doorway>* doorways;
};

#endif // PASSAGEWAY_H
