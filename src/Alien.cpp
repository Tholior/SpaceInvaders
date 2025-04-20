#include "Alien.hpp"

Texture2D Alien::alienImages[3] = {};

Alien::Alien(int type, Vector2 position) {
    this -> type = type;
    this -> position = position;

    if (alienImages[type - 1].id == 0) {
        switch (type) {
            case 1:
                alienImages[0] = LoadTexture("assets/alien_1.png");
                break;
            case 2:
                alienImages[1] = LoadTexture("assets/alien_2.png");
                break;
            case 3:
                alienImages[2] = LoadTexture("assets/alien_3.png");
                break;
            default:
                alienImages[0] = LoadTexture("assets/alien_1.png");
                break;
        }
    }
}
void Alien::Update(int direction) {
    position.x += direction;
}

void Alien::Draw() {
    DrawTextureV(alienImages[type - 1], position, WHITE);
}

int Alien::GetType() {
    return type;
}

void Alien::UnloadImages() {
    for (int i = 0; i < 3; i++) {
        UnloadTexture(alienImages[i]);
    }
}

Rectangle Alien::getRect() {
    return {position.x, position.y,
        static_cast<float>(alienImages[type - 1].width),
        static_cast<float>(alienImages[type - 1].height)
    };
}
