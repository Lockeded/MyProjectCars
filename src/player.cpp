#include "player.h"

Player::Player() : hp(3), score(0) { }

void Player::loseHP() {
    hp--;
}

void Player::addHP() {
    hp++;
}

void Player::addScore(int score) {
    this->score += score;
}

void Player::setHighestScore(int score) {
    highestScore = score;
}