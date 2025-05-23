#pragma once

#include <raylib.h>

class Mysteryship {
public:
    Mysteryship();
    ~Mysteryship();

    void Update();
    void Draw();
    void Spawn();
    Rectangle getRect();

    bool alive;

private:
    Vector2 position;
    Texture2D image;
    int speed;
};