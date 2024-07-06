#include "renderer.h"
#include <iostream>
#include <chrono>
#include <thread>

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
        std::cout << "\t\t\t\t\t" << segments[i] << std::endl;
    }

    for (int i = 0; i < carHeight; i++) {
        std::string leftSegment = segments[i+trackHeight - carHeight - carY].substr(0, carX - carWidth/2);
        std::string rightSegment = segments[i+trackHeight - carHeight -carY].substr(carX + carWidth/2 + 1);
        std::cout << "\t\t\t\t\t" << leftSegment << model[i] << rightSegment << std::endl;
    }

    for (int i = trackHeight - carY; i < trackHeight; i++) {
        std::cout << "\t\t\t\t\t" << segments[i] << std::endl;
    }
}

void Renderer::clearScreen() {
    std::cout << "\033[2J\033[1;1H";
}

void Renderer::renderOpeningScene() {
    std::vector<std::string> logo = readFile("assets/logo.txt");
    for(int i = 0; i < 100; i++) {
        clearScreen();
        for (const std::string& line : logo) {
            std::cout << line.substr(100-i) << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(15));
    }
    std::this_thread::sleep_for(std::chrono::milliseconds(2000));
}