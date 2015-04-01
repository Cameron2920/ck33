#ifndef ORC_H
#define ORC_H
#include "playablecharacter.h"
class Orc : public PlayableCharacter
{
public:
    Orc();
    virtual void collectGoldPile(GoldPile* goldPile);
};

#endif // ORC_H
