VVVVVV over 30 FPS mod - Version 1.1
-

This fork is now obsolete as the original repository has better support for over 30 fps support than this fork has.
I recommend you use the original repository for over 30 FPS support instead.

Here is the original readme:

Why
-
Because it looks nice

How
-
There are two methods that could be used.

1) Changing all the fixed timestep functions to use different variables. For example, multiplying the an entity's velocity by 0.5 when calculating the new position allows for the game to run at 60fps without speeding up. Some integers would need to be changed to floats as well.

2) Using linear interpolation so that the game is updated at 30fps, but is rendered at above 30fps.

I am using Method 2, as method 1 involves too many variables for me to find.

Method 2 has a disadvantage of 1/30th of a second worth of latency.

Extrapolation could maybe be used instead to solve this at the disadvantage of wrong predictions.

What works
-
All entities that move are interpolated (this is done by updating their old position before they are moved)

All backgrounds that move use deltatime

Variables set related to colour/animations/flashing/screenshake/messageboxes/glitched level names have been moved from the new variable render function to fixed render function.

Creation of entities sets more variables to be more accurate needed to avoid inaccurate rendering for first frame (this includes old position, animation frames, colour transform, and spawning of "LIES" and clouds being slightly off, and "Maverick bus" in "B-B-B-Busted")

Screen wrapping updates the old position so that the player doesn't very quickly move across the screen to get to the other side

The Tower "map" is interpolated

The game logic function and the game fixed render functions have been swapped, meaning logic is now processed before rendering, apart from variables related to onground and onroof so that edge-flipping can still be done.

"Fade" transitions use linear interpolation

Deltatime is slowed down if playing on slowmode

There should not be any game breaking issues

What doesn't work
-
Anything that's not in gamestate GAMEMODE does not render over 30 fps (NOT PLANNING ON DOING)

I'm compiling in release mode, which according to the build instructions should have issues, but I've not encountered any

and things that have not been tested yet might not work, like custom levels, having a brief look at them they seem to work but I don't have time to test them all

Bugs that occur in the original game still occur, I'm not planning on fixing these.

I found something that does not work that is related to this mod
-
Create a new issue on github, and I'll try to fix the issue if I have time, even if it's something minor like an enemy being rendered in the wrong place for 1 frame

What's been tested
-
100% of the main game

any% of the main game

15 seconds of the Super Gravitron in the Secret Lab

All Time Trials

any% of the main game flipped

1 Time Trial flipped

When are you going to update it
-
I have now done everything I wanted to do with this mod, but if there are any issues, or I am wanting to procrastinate maybe I'll interpolate the menu's and credits

Feel free to take all the code I added, update it, claim it as your own.
