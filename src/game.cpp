#include "game.h"


Game::Game() : isRunning(true) {
    std::string trackFile = "assets/track.txt";
    track.load(trackFile);
    
    std::string carFile = "assets/car.txt";
    car.loadCar(carFile); // 假设 Car 类有一个用于加载车辆数据的函数 loadCar()

    std::string monsterFile = "assets/monster.txt";
    monster.loadMonster(monsterFile); // 假设 Monster 类有一个用于加载怪物数据的函数 loadMonster()
}

// Function to set terminal to non-canonical mode
void setNonCanonicalMode() {
    struct termios newSettings;
    tcgetattr(STDIN_FILENO, &newSettings);

    newSettings.c_lflag &= ~(ICANON | ECHO);
    newSettings.c_cc[VMIN] = 1;
    newSettings.c_cc[VTIME] = 0;

    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

// Function to restore terminal to canonical mode
void restoreCanonicalMode() {
    struct termios newSettings;
    tcgetattr(STDIN_FILENO, &newSettings);

    newSettings.c_lflag |= (ICANON | ECHO);

    tcsetattr(STDIN_FILENO, TCSANOW, &newSettings);
}

// Function to check if a key has been pressed
bool kbhit() {
    struct timeval tv = { 0L, 0L };
    fd_set fds;
    FD_ZERO(&fds);
    FD_SET(STDIN_FILENO, &fds);
    return select(STDIN_FILENO + 1, &fds, NULL, NULL, &tv) > 0;
}

// Function to get a character without waiting for Enter key
int getch() {
    int r;
    unsigned char c;
    if ((r = read(STDIN_FILENO, &c, sizeof(c))) < 0) {
        return r;
    } else {
        return c;
    }
}

void Game::run() {
    setNonCanonicalMode();
    openingScene();
    while (isRunning) {
        processInput();
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(30));
    }
    renderer.clearScreen();
    restoreCanonicalMode();
}

void Game::processInput() {
    if (kbhit()) {
        switch (getch()) {
            case 'a':
                car.steerLeft();
                break;
            case 'd':
                car.steerRight();
                break;
            case 'w':
                car.accelerate();
                car.steerCenter();
                break;
            case 's':
                car.brake();
                car.steerCenter();
                break;
            case 'q':
                isRunning = false;
                break;
            case ' ':
                car.steerCenter();
                break;
        }
    }
}

void Game::update() {
    car.update(track);
}


void Game::render() {
    renderer.draw(car, track);
}

void Game::openingScene() {
    renderer.renderOpeningScene();
}
