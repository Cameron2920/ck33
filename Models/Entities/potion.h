 #ifndef POTION_H
#define POTION_H

#include "entity.h"

class Potion : public Entity {
public:
    enum EffectedAttribute { AttackPoints, DefensePoints, HealthPoints };
    Potion();
    Potion(EffectedAttribute effectedAttribute, int effectAmount);
    Potion(Potion* potion);
    int getEffectAmount();
    void setEffectAmout(int effectAmount);
    EffectedAttribute getEffectedAttribute();
    void setEffectedAttribute(EffectedAttribute effectedAttribute);
private:
    int effectAmount;
    EffectedAttribute effectedAttribute;
};

#endif // POTION_H
