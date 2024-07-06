#ifndef RENDERER_H
#define RENDERER_H

#include "car.h"
#include "track.h"
#include "player.h"
#include "monster.h"
#include <vector>
#include <string>

class Renderer {
public:
    Renderer();
    void draw(const Car &car, const Track &track);
    void clearScreen();
    void renderOpeningScene();
private:
    std::vector<std::string> logo;
};
#endif // RENDERER_H