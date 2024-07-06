#include "renderer.h"
#include <iostream>

Renderer::Renderer(){}

void Renderer::draw(const Car &car, const Track &track) {
    clearScreen();
    
    std::vector<std::string> model = car.getModel();
    std::vector<std::string> segments = track.getSegments();
    int carX = car.getPositionX();
    int carY = car.getPositionY();
    int carWidth = car.getCarWidth();
    int carHeight = car.getCarHeight();
    int trackWidth = track.getTrackWidth();
    int trackHeight = track.getTrackHeight();

    for (int i = 0; i < trackHeight - carHeight - carY; i++) {
        std::cout << segments[i] << std::endl;
    }

    for (int i = 0; i < carHeight; i++) {
        std::string leftSegment = segments[i+trackHeight - carHeight - carY].substr(0, carX - carWidth/2);
        std::string rightSegment = segments[i+trackHeight - carHeight -carY].substr(carX + carWidth/2 + 1);
        std::cout << leftSegment << model[i] << rightSegment << std::endl;
    }

    for (int i = trackHeight - carY; i < trackHeight; i++) {
        std::cout << segments[i] << std::endl;
    }
}

void Renderer::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
