#include "car.h"
#include "utils.h"

Car::Car() : positionX(10),positionY(0),direction(0),speed(0),acceleration(0) {}

void Car::update(Track track) {
    positionX += direction;
    if (positionX < 5+carWidth/2) positionX = 5+carWidth/2;
    if (positionX > track.getTrackWidth() - carWidth/2 -1 ) positionX = track.getTrackWidth() - carWidth/2 -1;
    positionY += speed;
    if (positionY > track.getTrackHeight() - carHeight) positionY = track.getTrackHeight() - carHeight;
    speed+=acceleration;
    if(speed>maxSpeed) speed = maxSpeed;
    if(speed<0) speed = 0; //未实现倒车功能
}

void Car::steerLeft() {
    direction = -1;
}

void Car::steerCenter() {
    direction = 0;
}

void Car::steerRight() {
    direction = 1;
}

void Car::accelerate() {
    acceleration += 1;
}

void Car::brake() {
    acceleration -= 1;
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