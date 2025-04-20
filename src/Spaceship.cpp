#include "Spaceship.hpp"
#include <iostream>

Spaceship::Spaceship() {
    image = LoadTexture("assets/spaceship.png");
    position.x = GetScreenWidth() / 2 - image.width / 2;
    position.y = GetScreenHeight() - image.height - 100;
    lastFireTime = 0;
    laserSound = LoadSound("assets/laser.ogg");
}

Spaceship::~Spaceship() {
    UnloadTexture(image);
    UnloadSound(laserSound);
}

void Spaceship::Draw() {
    DrawTextureV(image, position, WHITE);
}

void Spaceship::MoveLeft() {
    position.x -= spaceshipMovementSpeed;
    if (position.x < 25 ) {
        position.x = 25;
    }
}

void Spaceship::MoveRight() {
    position.x += spaceshipMovementSpeed;
    if (position.x > GetScreenWidth() - image.width - 25) {
        position.x = GetScreenWidth() - image.width - 25;
    }
}

void Spaceship::FireLaser() {
    if (GetTime() - lastFireTime >= 0.35) {
        lasers.push_back(Laser({position.x + image.width/2 - 2, position.y}, -6));
        lastFireTime = GetTime();
        PlaySound(laserSound);
    }
}

void Spaceship::Reset() {
    position.x = (GetScreenWidth() - image.width) / 2.0f;
    position.y = GetScreenHeight() - image.height - 100;
    lasers.clear();
}

Rectangle Spaceship::getRect() {
    return {position.x, position.y, static_cast<float>(image.width), static_cast<float>(image.height)};
}

