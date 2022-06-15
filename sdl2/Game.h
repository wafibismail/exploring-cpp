#ifndef _Game_h
#define _Game_h

#include "SDL2\SDL.h"

struct Vector2 {
    float x;
    float y;
};

class Game {
public:
    Game();
    // Initialize the game
    bool Initialize();
    // Runs the game loop until the game is over
    void RunLoop();
    // Shutdown the game
    void Shutdown();
private:
    // Helper functions for the game loop
    void ProcessInput();
    void UpdateGame();
    void GenerateOutput();

    // Window created by SDL
    SDL_Window* mWindow;
    // Game should continue to run
    bool mIsRunning;

    SDL_Renderer* mRenderer;
    const int thickness = 15; // for use in rendering
    Vector2 mPaddlePos;
    Vector2 mBallPos;
};

#endif