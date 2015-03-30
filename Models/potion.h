 #ifndef POTION_H
#define POTION_H

#ifdef CHARACTER_H
class Character;
#else
#include "character.h"
#endif

class Potion : public Entity {
public:
    enum EffectedAttribute { AttackPoints, DefensePoints, HealthPoints };
    Potion();
    Potion(EffectedAttribute effectedAttribute, int effectAmount);
    int getEffectAmount();
    void setEffectAmout(int effectAmount);
    EffectedAttribute getEffectedAttribute();
    void setEffectedAttribute(EffectedAttribute effectedAttribute);
private:
    int effectAmount;
    EffectedAttribute effectedAttribute;
};

#endif // POTION_H
