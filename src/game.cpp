#include "game.h"

Game::Game() : isRunning(true) {
    std::string trackFile = "assets/track.txt";
    track.load(trackFile);
    
    std::string carFile = "assets/car.txt";
    car.loadCar(carFile); // 假设 Car 类有一个用于加载车辆数据的函数 loadCar()
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

// Function to get all characters without waiting for Enter key
std::vector<int> getAllChars() {
    std::vector<int> chars;
    while (kbhit()) {
        unsigned char c;
        if (read(STDIN_FILENO, &c, sizeof(c)) > 0) {
            chars.push_back(c);
        }
    }
    return chars;
}

void Game::run() {
    setNonCanonicalMode();
    auto lastInputTime = std::chrono::system_clock::now();
    auto inputInterval = std::chrono::milliseconds(100);

    while (isRunning) {
        auto currentTime = std::chrono::system_clock::now();
        auto deltaTime = std::chrono::duration_cast<std::chrono::milliseconds>(currentTime - lastInputTime);
        if (deltaTime >= inputInterval) {
            processInput();
            lastInputTime = currentTime;
        }
        update();
        render();
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    }
    restoreCanonicalMode();
}

void Game::processInput() {
    std::vector<int> chars = getAllChars();
    bool steerLeft = false, steerRight = false, accelerate = false, brake = false;

    for (int ch : chars) {
        switch (ch) {
            case 'a':
                steerLeft = true;
                break;
            case 'd':
                steerRight = true;
                break;
            case 'w':
                accelerate = true;
                break;
            case 's':
                brake = true;
                break;
            case 'q':
                isRunning = false;
                break;
            case ' ':
                car.steerCenter();
                break;
        }
    }

    if (steerLeft) {
        car.steerLeft();
    }
    if (steerRight) {
        car.steerRight();
    }
    if (accelerate) {
        car.accelerate();
    }
    if (brake) {
        car.brake();
    }
}

void Game::update() {
    car.update(track);
}

void Game::render() {
    renderer.draw(car, track);
}
