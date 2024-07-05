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

    // Ensure car position is within track bounds
    carX = std::max(0, std::min(carX, trackWidth - carWidth));

    for (int i = 0; i < trackHeight - carHeight; i++) {
        std::cout << segments[i] << std::endl;
    }

    for (int i = 0; i < carHeight; i++) {
        std::string leftSegment = segments[trackHeight - carHeight + i].substr(0, carX);
        std::string rightSegment = segments[trackHeight - carHeight + i].substr(carX + carWidth);

        // Ensure the lengths match the track width
        if (leftSegment.size() + carWidth + rightSegment.size() > trackWidth) {
            rightSegment = rightSegment.substr(0, trackWidth - leftSegment.size() - carWidth);
        }

        std::cout << leftSegment << model[i] << rightSegment << std::endl;
    }
}

void Renderer::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}
