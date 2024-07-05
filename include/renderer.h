#ifndef RENDERER_H
#define RENDERER_H

#include "car.h"
#include "track.h"
#include <vector>
#include <string>

class Renderer {
public:
    Renderer();
    void draw(const Car &car, const Track &track);
private:
    void clearScreen();
};
#endif // RENDERER_H