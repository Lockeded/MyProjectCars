#ifndef MONSTER_H
#define MONSTER_H

#include <vector>
#include <string>
#include "utils.h"

class Monster {
public:
    Monster();
    int getMonsterPosX() const {return MonsterPosX;};
    int getMonsterPosY() const {return MonsterPosY;};
    int getMonsterWidth() const {return MonsterWidth;};
    int getMonsterHeight() const {return MonsterHeight;};
    void loadMonster(std::string filename);
    std::vector<std::string> getMonsterModel() const {return monsterModel;};
private:
    int MonsterPosX;
    int MonsterPosY;
    int MonsterWidth;
    int MonsterHeight;
    std::vector<std::string> monsterModel;
};


#endif // !MONSTER_H
