#include <iostream>
#include <raylib.h>
#include "Game.hpp"

using namespace std;

string FormatWithLeadingZeros(int number, int width) {
    string numberText = to_string(number);
    int leadingZeros = width - numberText.length();
    return numberText = string(leadingZeros, '0') + numberText;
}

int main() {
    const Color grey = {29, 29, 27, 255};
    const Color yellow = {243, 216, 63, 255};
    const int offset = 50;
    const int windowWidth = 750;
    const int windowHeight = 700;

    InitWindow(windowWidth + offset, windowHeight + 2 * offset, "Space Invaders");
    SetTargetFPS(60);
    InitAudioDevice();

    Font font = LoadFontEx("assets/monogram.ttf", 64, nullptr, 0);
    Texture2D spaceshipImage = LoadTexture("assets/spaceship.png");

    Game game;

    while (WindowShouldClose() == false) {

        UpdateMusicStream(game.music);

        game.HandleInput();
        game.Update();

        BeginDrawing();
        ClearBackground(grey);

        DrawRectangleRoundedLinesEx({10, 10, 780, 780}, 0.18f, 20, 4, BLUE);
        DrawLineEx({25, 730}, {775, 730}, 3, BLUE);
        if (game.run) {
            DrawTextEx(font, "Level 01", {570, 740}, 34, 2, RED);
        }
        else {
            DrawTextEx(font, "GAME OVER", {570, 740}, 34, 2, RED);
        }

        float x = 50;
        for (int i = 0; i < game.lives; i++) {
            DrawTextureV(spaceshipImage, {x, 745}, WHITE);
            x += 50;
        }

        DrawTextEx(font, "SCORE", {50, 15}, 34, 2, RED);
        string scoreText = FormatWithLeadingZeros(game.score, 5);
        DrawTextEx(font, scoreText.c_str(), {50, 40}, 34, 2, RED);

        DrawTextEx(font, "HIGH-SCORE", {570, 15}, 34, 2, RED);
        string highscoreText = FormatWithLeadingZeros(game.highscore, 5);
        DrawTextEx(font, highscoreText.c_str(),{655, 40}, 34, 2, RED);

        game.Draw();
        EndDrawing();
    }
    CloseWindow();
    CloseAudioDevice();

    return 0;
}