#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H
#include "moveablecharacter.h"

#ifdef POTION_H
class Potion;
#else
#include "potion.h"
#endif

#include "goldpile.h"
#include "resizeablearray.t.hpp"

class PlayableCharacter : public MoveableCharacter {
public:
    PlayableCharacter();
    PlayableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race);
    void consumePotion(Potion* potion);
    virtual void collectGoldPile(GoldPile* goldPile);
    void digestPotions();
    void incrementNumberOfCompletedFloors();
    int getNumberOfCompletedFloors();
    void setValueOfGoldCollected(int valueOfGoldCollected);
    int getValueOfGoldCollected();
private:
    bool hasAttackedMerchant;
    ResizeableArray<Potion>* consumedPotions;
    int valueOfGoldCollected;
    virtual void applyPotionEffect(Potion* potion);
    virtual void unapplyPotionEffect(Potion* potion);
    int numberOfCompletedFloors;

    friend std::ostream& operator<<(std::ostream& os, PlayableCharacter* player);
};

#endif // PLAYABLECHARACTER_H
