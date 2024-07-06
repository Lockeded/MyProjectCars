#include "monster.h"

Monster::Monster(){}

void Monster::loadMonster(std::string filename) {
    monsterModel = readFile(filename);
}