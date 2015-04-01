#ifndef ELF_H
#define ELF_H

#include "playablecharacter.h"
#include <cmath>

class Elf : public PlayableCharacter
{
public:
    Elf();
    virtual void applyPotionEffect(Potion* potion);
    virtual void unapplyPotionEffect(Potion* potion);
};

#endif // ELF_H
