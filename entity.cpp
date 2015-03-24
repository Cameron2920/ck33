#include "entity.h"

Entity::Entity(){
}

Entity::~Entity(){
    if(cell){
        cell->setEntity(0);
    }
}

Cell* Entity::getCell(){
    return cell;
}

void Entity::setCell(Cell* cell){
    this->cell = cell;
}

char Entity::getTerminalDisplayCharacter(){
    return terminalDisplayCharacter;
}

void Entity::setTerminalDisplayCharacter(char terminalDisplayCharacter){
    this->terminalDisplayCharacter = terminalDisplayCharacter;
}

std::ostream& operator<<(std::ostream& os, Entity* entity){
    os << entity->getTerminalDisplayCharacter();
    return os;
}
