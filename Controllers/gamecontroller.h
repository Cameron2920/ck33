#ifndef GAMECONTROLLER_H
#define GAMECONTROLLER_H
#include "floor.h"
#include "rules.h"
#include "initializer.h"
#include "artificialintelligence.h"
#include "Entities/Characters/MoveableCharacters/PlayableCharacters/human.h"
#include "Entities/Characters/MoveableCharacters/PlayableCharacters/orc.h"
#include "Entities/Characters/MoveableCharacters/PlayableCharacters/elf.h"
#include "Entities/Characters/MoveableCharacters/PlayableCharacters/dwarf.h"
#include <iostream>
#include <sstream>
#define INT_TO_STRING( x ) dynamic_cast< std::ostringstream & >( ( std::ostringstream() << std::dec << x ) ).str()

void gameController();
std::string simulateEnemyTurns(Floor* floor, Rules* rules, PlayableCharacter* player);
Cell* findCellByDirection(PlayableCharacter* player, std::string direction);
void display(Floor* floor, PlayableCharacter* player, std::string action);
std::string playerAttack(Rules* rules, PlayableCharacter* player, std::string direction, Floor* floor);
std::string movePlayer(Floor* floor, Rules* rules, PlayableCharacter* player, std::string direction);
std::string usePotion(Rules* rules, PlayableCharacter* player, std::string direction, Floor* floor);
PlayableCharacter* selectCharacter();

#endif // GAMECONTROLLER_H
