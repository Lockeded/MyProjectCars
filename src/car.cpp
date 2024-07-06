#include "car.h"
#include "utils.h"

Car::Car() : positionX(25),positionY(0),direction(0),speed(0),acceleration(0) {}

void Car::update(Track track) {
    if (positionX < 15 + carWidth/2) positionX = 15 + carWidth/2;
    if (positionX > track.getTrackWidth() - carWidth/2 -15) positionX = track.getTrackWidth() - carWidth/2 -15;
    if (positionY > track.getTrackHeight() - carHeight) positionY = track.getTrackHeight() - carHeight;
    if (positionY < 0) positionY = 0;
}

void Car::steerLeft() {
    positionX += -1;
}

void Car::steerCenter() {
    direction = 0;
}

void Car::steerRight() {
    positionX += 1;
}

void Car::accelerate() {
    positionY += 1;
}

void Car::brake() {
    positionY += -1;
}

int Car::getPositionX() const {
    return positionX;
}

int Car::getPositionY() const {
    return positionY;
}

int Car::getSpeed() const {
    return speed;
}

int Car::getDirection() const {
    return direction;
}

int Car::getAcceleration() const {
    return acceleration;
}

int Car::getMaxSpeed() const {
    return maxSpeed;
}

void Car::loadCar(std::string filename){
    model = readFile(filename);
    carHeight = model.size();
    carWidth = model[0].size();
}