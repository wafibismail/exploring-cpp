Based on:
- Book: Game Programming in C++: Creating 3D Games (Game Design)
- Author: Sanjay Madhav<br>

Paused at 4% progress i.e. just before "Updating the Game"<br>

I find it is a very good book, but at this point I've switched to working on something else; I intend to resume following this book/course sometime in the distant future.

- dependency:
  - SDL2
- In each frame, at high level, a game:
  - 1) processes any input
    - e.g. the player, other players, external e.g. GPS information
  - 2) updates the game world
    - e.g. characters, objects, UI
  - 3) generates any output
    - graphics, audio
    - force feedback effects e.g. controller vibration when something happens
- events : a common way to represent actions such as:
  - window being moved, minimized, maximized, closed by the user, and so on
  - when any of these happen, the program receives an event from the operating system and can choose to respond to it (or to ignore it)
- SDL manages an internal queue of events
  - every frame, the game polls the queue for any event
- color buffer : location in memory containing color information for the entire screen
  - in each frame, in "generate outputs" phase of the game loop, the game writes graphical output into the color buffer
  - the memory usage depends on the number of bits that represent each pixel i.e. the **color depth**
    - e.g.:
      - in the common 24-bit color depth, each of red, green & blue use 8 bits
        - 2^24 = 16777216 unique colors
        - or 32 bits for each pixel if the game also wants to store an 8 bit alpha values
      - a color buffer for 1080p (1920x1080) target resolution with 32 bits per pixel uses 1920x1080x4 bytes = 7.9MB approx
- Ways of referencing the value of a color e.g. in the case of 8 bit per color:
  - a.. use an unsigned integer corresponding to the number of bits for each color (or channel), so each channel has a value between 0 to 256, or:
  - b.. normalize the integer over a decimal range from 0.0 to 1.0
    - which has the advantage that a value yields roughly the same color regardless of color depth e.g. (1.0, 0.0, 0.0) yields pure red, though (256, 0, 0) would yield pure red only if there are 8 bits per color
- refresh rate i.e. frequency at which the display updates may be different from the game's frame rate
  - the screen is not updated entirely at once; there is always some order e.g.:
    - row by row
    - column by column
    - checkerboard, etc.
  - it takes some fraction of a second for the whole screen to update
- screen tearing : when the display shows part of two frames
  - eliminated by the combination of:
    - double buffering:
      - the game can write to one buffer (the back buffer)
      - while the display can read from the other buffer (front buffer)
      - the game and display swap their buffers after the game completes
    - vertical synchronization (vsync)
      - require waiting for the display to finish drawing its buffer before swapping when the game wants to swap buffers
      - HOWEVER vsync may cause stuttering as the target frame rate of 30 or FPS may not be achieved, thus the decision on enabling it varies depending on the game or player
        - advisable to offer vsync as an option in the engine so can choose between occasional screen tearing or occasional stuttering
      - alternatively: adaptive refresh:
        - rather than the display notifying the game when it refreshes, the game tells the display when to refresh. this way, the game and display are in sync
        - though this is only available on certain high-end monitors
- renderer: any system that draws graphics
- Basic drawing setup:
  - 1.. Clear the back buffer to a color (the game's current buffer)
  - 2.. Draw the entire game screen
  - 3.. Swap the front buffer and back buffer