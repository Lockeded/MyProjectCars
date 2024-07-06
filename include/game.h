#ifndef GAME_H
#define GAME_H

#include <termios.h>
#include <unistd.h>
#include <chrono>
#include <iostream>
#include <thread>
#include "renderer.h"
#include "track.h"
#include "car.h"
#include "utils.h"
#include "player.h"
#include "monster.h"

class Game {
public:
    Game();
    void run();
private:
    void processInput();
    void update();
    void render();
    void openingScene();

    Renderer renderer;
    Track track;
    Car car;
    Player player;
    Monster monster;
    bool isRunning;
};
#endif // GAME_H
