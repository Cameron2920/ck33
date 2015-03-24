#ifndef GOLDPILE_H
#define GOLDPILE_H
#include "entity.h"
class GoldPile : public Entity{
public:
    GoldPile();
    GoldPile(int value);
    int getValue();
    void setValue(int value);
private:
    int value;
};

#endif // GOLDPILE_H
