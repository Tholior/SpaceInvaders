#pragma once

#include <raylib.h>
#include <iostream>
#include "Laser.hpp"
#include <vector>

class Spaceship {
public:
    Spaceship();
    ~Spaceship();

    void Draw();
    void MoveLeft();
    void MoveRight();
    void FireLaser();
    void Reset();
    Rectangle getRect();

    std::vector<Laser> lasers;

private:
    Texture2D image;
    Vector2 position;
    float spaceshipMovementSpeed = 7;
    double lastFireTime;
    Sound laserSound;
};
