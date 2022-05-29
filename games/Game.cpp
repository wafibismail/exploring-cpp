/*
 * File: Game.cpp
 * --------------
 * Implementation to the interface Game.h
 */

#include "Game.h"

Game::Game() { }

/*
 * Implementation notes: Initialize
 * --------------------------------------
 * Within this method:
 * 1. The SDL library is initialized with the SDL_Init function, which
 * takes a single parameter, a bitwise OR of all subsystems to initialize.
 * 
 * Subsystems flags e.g.:
 * - SDL_INIT_AUDIO
 * - SDL_INIT_VIDEO
 * - SDL_INIT_HAPTIC
 * - SDL_INIT_GAMECONTROLLER
 * 
 * 2. A window is created with SDL_CreateWindow, which takes in several
 * parameters:
 * - the title of the window
 * - the top-left corner x/y coordinates
 * - the width/height of the window
 * - (optional) any window creation flags
 * 
 * Window creation flags e.g.:
 * - SDL_WINDOW_FULLSCREEN
 * - SDL_WINDOW_FULLSCREEN_DESKTOP
 * - SDL_WINDOW_OPENGL
 * - SDL_WINDOW_RESIZABLE
 * 
 * Initialize returns true if all these succeed:
 * - SDL initialization
 * - Window creation
 * 
 * False otherwise
 */

bool Game::Initialize() {
    // SDL_Init returning nonzero indicates failure
    int sdlResult = SDL_Init(SDL_INIT_VIDEO);
    if (sdlResult != 0) {
        // SDL_Log is a simple way to output messages to the console
        // SDL_GetError returns an error message as a C-style string
        // which is why it's passed as a %s
        SDL_Log("Unable to initialize SDL: %s", SDL_GetError());
        return false;
    }

    mWindow = SDL_CreateWindow(
        "Game Programming in C++ (Chapter 1)",
        100,    // Top-left x coordinate of the window
        100,    // Top-left y coordinate of the window
        1024,   // Width of window
        768,    // Height of window
        0       // Flags (0 for no flags set)
    );

    /* As with SDL_Init, SDL_CreateWindow execution need to be verified */

    if (!mWindow) { // if mWindow is nulltpr
        SDL_Log("Failed to create window: %s", SDL_GetError());
        return false;
    }

    mRenderer = SDL_CreateRenderer(
        mWindow,    // Window to create renderer for
        -1,         // Usually -1
        SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC
    );

    // If both SDL initialization and window creation succeeds:
    mIsRunning = true;
    return true;
}

/*
 * Implementation notes: Shutdown
 * ------------------------------------
 * This method does the opposite of Initialize, i.e:
 * - destroys SDL_Window with SDL_DestroyWindow
 * - closes SDL using SDL_Quit
 */

void Game::Shutdown() {
    SDL_DestroyWindow(mWindow);
    SDL_Quit();
}

/*
 * Implementation notes: RunLoop
 * -----------------------------------
 * This method keeps running iterations of the game loop until
 * mIsRunning becomes false, at which point the function returns.
 */

void Game::RunLoop() {
    while (mIsRunning) {
        ProcessInput();
        UpdateGame();
        GenerateOutput();
    }
}

/*
 * Implementation notes: ProcessInput
 * ----------------------------------
 * Processes any input e.g. change mIsRunning (the sentinel) to false
 * if either the X button is clicked or escape key is pressed
 * 
 * SDL_PollEvent returns true if it finds any event in the queue
 */

void Game::ProcessInput() {
    SDL_Event event;
    while (SDL_PollEvent(&event)) { // also polls and stores the event
        switch (event.type) {
            case SDL_QUIT: // when the close button is clicked
                mIsRunning = false;
                break;
        }
    }
    const Uint8* state = SDL_GetKeyboardState(NULL);
    if (state[SDL_SCANCODE_ESCAPE]) {
        mIsRunning = false;
    }
}
void Game::UpdateGame() {}
void Game::GenerateOutput() {}