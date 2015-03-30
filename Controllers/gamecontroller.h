#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "../Models/floor.h"
#include "../Models/rules.h"
#include "../Models/initializer.h"
#include "../Models/artificialintelligence.h"
#include "../Models/human.h"
#include <iostream>

void gameController();
void simulateEnemyTurns(Floor* floor, Rules* rules, PlayableCharacter* player);
Cell* findCellByDirection(PlayableCharacter* player, std::string direction);
void display(Floor* floor, PlayableCharacter* player);

#endif // GAMECONTROLLER_H
