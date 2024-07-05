#ifndef CAR_H
#define CAR_H

#include "track.h"
#include <vector>
#include <string>
#include <fstream>


class Car {
public:
    Car();
    void update(Track track);
    void steerLeft();
    void steerRight();
    void steerCenter();
    void accelerate();
    void brake();
    int getPositionX() const;
    int getPositionY() const;
    int getSpeed() const;
    int getDirection() const;
    int getAcceleration() const;
    int getMaxSpeed() const;
    int getCarWidth() const { return carWidth; }
    int getCarHeight() const { return carHeight; }
    void loadCar(std::string filename);
    std::vector<std::string> getModel() const { return model; }
private:
    int positionX;
    int positionY;
    int speed;
    int acceleration;
    int direction;
    int carWidth;
    int carHeight;
    std::vector<std::string> model;
    static const int maxSpeed = 10;
};
#endif // CAR_H