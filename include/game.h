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

class Game {
public:
    Game();
    void run();
private:
    void processInput();
    void update();
    void render();

    Renderer renderer;
    Track track;
    Car car;
    bool isRunning;
};
#endif // GAME_H
