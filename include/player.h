#ifndef PLAYER_H
#define PLAYER_H

class Player {
public:
    Player();
    int getHP(){return hp;};
    int getScore(){return score;};
    int getHighestScore(){return highestScore;};
    void loseHP();
    void addHP();
    void addScore(int score);
    void setHighestScore(int score);
private:
    int hp;
    int score;
    int highestScore;
};

#endif // !PLAYER_H
