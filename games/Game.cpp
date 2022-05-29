/*
 * File: Game.cpp
 * --------------
 * Implementation to the interface Game.h
 */

#include "Game.h"

Game::Game() { }

/*
 * Implementation notes: Game::Initialize
 * --------------------------------------
 * Here the SDL library is initialized with the SDL_Init function, which
 * takes a single parameter, a bitwise OR of all subsystems to initialize.
 * Subsystems flags e.g.:
 * - SDL_INIT_AUDIO
 * - SDL_INIT_VIDEO
 * - SDL_INIT_HAPTIC
 * - SDL_INIT_GAMECONTROLLER
 * 
 * Initialize returns true if initialization succeeds, false otherwise.
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

    /*
     * The SDL_CreateWindow takes in several parameters:
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
     */

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

    // If both SDL initialization and window creation succeeds:
    return true;
}