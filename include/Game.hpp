#pragma once
#include "Spaceship.hpp"
#include "Obstacle.hpp"
#include "Alien.hpp"
#include "Mysteryship.hpp"

class Game {
public:
    Game();
    ~Game();

    void Draw();
    void Update();
    void HandleInput();

    bool run;
    int lives;
    int score;
    int highscore;
    Music music;

private:
    void InitGame();
    void Reset();
    void GameOver();
    void DeleteInactiveLasers();
    std::vector<Obstacle> CreateObstacles();
    std::vector<Alien> CreateAliens();
    void MoveAliens();
    void MoveAliensDown(int distance);
    void AlienShootLaser();
    void CheckForCollisions();
    void CheckForHighscore();
    void saveHighscoreToFile(int highscore);
    int loadHighscoreFromFile();

    Sound explosionSound;
    Spaceship spaceship;
    Mysteryship mysteryShip;
    std::vector<Obstacle> obstacles;
    std::vector<Alien> aliens;
    int aliensDirection;
    std::vector<Laser> alienLasers;
    constexpr static float alienLaserShootInterval = 0.35;
    float timeLastAlienFired;
    float mysteryShipSpawnInterval;
    float timeLastMysteryShipSpawn;
};