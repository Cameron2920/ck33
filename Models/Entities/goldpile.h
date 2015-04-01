#ifndef GOLDPILE_H
#define GOLDPILE_H
#include "entity.h"
class GoldPile : public Entity{
public:
    GoldPile();
    enum Type { Normal, SmallHorde, MerchantHorde, DragonHorde };
    GoldPile(int value);
    int getValue();
    void setValue(int value);
private:
    int value;
};

#endif // GOLDPILE_H
