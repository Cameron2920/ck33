#-------------------------------------------------
#
# Project created by QtCreator 2015-03-27T19:36:11
#
#-------------------------------------------------

QT       += core

QT       -= gui

TARGET = ck33
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    Models/artificialintelligence.cpp \
    Models/floor.cpp \
    Models/initializer.cpp \
    Models/rules.cpp \
    Models/Entities/entity.cpp \
    Models/Entities/goldpile.cpp \
    Models/Entities/ladder.cpp \
    Models/Entities/potion.cpp \
    Models/Cells/cell.cpp \
    Models/Cells/connector.cpp \
    Models/Cells/doorway.cpp \
    Models/Cells/resizeablecellarray.cpp \
    Models/Cells/wall.cpp \
    Models/Entities/Characters/character.cpp \
    Models/Entities/Characters/MoveableCharacters/moveablecharacter.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/dragon.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/enemycharacter.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/goblin.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/merchant.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/phoenix.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/troll.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/vampire.cpp \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/werewolf.cpp \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/dwarf.cpp \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/elf.cpp \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/human.cpp \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/orc.cpp \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/playablecharacter.cpp \
    Controllers/gamecontroller.cpp \
    Models/OpenSpaces/chamber.cpp \
    Models/OpenSpaces/openspace.cpp \
    Models/OpenSpaces/passageway.cpp

INCLUDEPATH += ./Models
INCLUDEPATH += ./Controllers

OTHER_FILES += \
    Models/Makefile \
    Models/Entities/Makefile \
    Models/Cells/Makefile \
    Models/Entities/Characters/Makefile \
    Models/Entities/Characters/MoveableCharacters/Makefile \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/Makefile \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/Makefile \
    Models/OpenSpaces/Makefile

HEADERS += \
    Models/artificialintelligence.h \
    Models/floor.h \
    Models/initializer.h \
    Models/resizeablearray.h \
    Models/resizeablearray.t.hpp \
    Models/rules.h \
    Models/Entities/entity.h \
    Models/Entities/goldpile.h \
    Models/Entities/ladder.h \
    Models/Entities/potion.h \
    Models/Cells/cell.h \
    Models/Cells/connector.h \
    Models/Cells/doorway.h \
    Models/Cells/resizeablecellarray.h \
    Models/Cells/wall.h \
    Models/Entities/Characters/character.h \
    Models/Entities/Characters/MoveableCharacters/moveablecharacter.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/dragon.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/enemycharacter.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/goblin.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/merchant.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/phoenix.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/troll.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/vampire.h \
    Models/Entities/Characters/MoveableCharacters/EnemyCharacters/werewolf.h \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/dwarf.h \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/elf.h \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/human.h \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/orc.h \
    Models/Entities/Characters/MoveableCharacters/PlayableCharacters/playablecharacter.h \
    Controllers/gamecontroller.h \
    Models/OpenSpaces/chamber.h \
    Models/OpenSpaces/openspace.h \
    Models/OpenSpaces/passageway.h
