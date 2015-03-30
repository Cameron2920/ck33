#ifndef DWARF_H
#define DWARF_H
#include "playablecharacter.h"

class Dwarf : public PlayableCharacter
{
public:
    Dwarf();
    virtual void collectGoldPile(GoldPile* goldPile);
};

#endif // DWARF_H
