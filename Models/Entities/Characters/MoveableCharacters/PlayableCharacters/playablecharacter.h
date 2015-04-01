#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H
#include "Entities/Characters/MoveableCharacters/moveablecharacter.h"

#ifdef POTION_H
class Potion;
#else
#include "Entities/potion.h"
#endif

#include "Entities/goldpile.h"
#include "resizeablearray.t.hpp"

class PlayableCharacter : public MoveableCharacter {
public:
    PlayableCharacter();
    PlayableCharacter(int healthPoints, int defensePoints, int attackPoints, Race race);
    ~PlayableCharacter();
    void consumePotion(Potion* potion);
    virtual void collectGoldPile(GoldPile* goldPile);
    void digestPotions();
    void incrementNumberOfCompletedFloors();
    int getNumberOfCompletedFloors();
    void setValueOfGoldCollected(int valueOfGoldCollected);
    int getValueOfGoldCollected();
    bool hasDiscoveredPotion(Potion* potion);
    void setHasAttackedMerchant(bool hasAttackedMerchant);
    bool getHasAttackedMerchant();
private:
    bool hasAttackedMerchant;
    ResizeableArray<Potion>* consumedPotions;
    ResizeableArray<Potion>* discoveredPotions;
    int valueOfGoldCollected;
    virtual void applyPotionEffect(Potion* potion);
    virtual void unapplyPotionEffect(Potion* potion);
    int numberOfCompletedFloors;

    friend std::ostream& operator<<(std::ostream& os, PlayableCharacter* player);
};

#endif // PLAYABLECHARACTER_H
