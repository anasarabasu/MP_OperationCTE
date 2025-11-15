/*
DESCRIPTION:
    A terminal game based on the anime—Spy x Family—where you play as Anya trying to get the best results in the math, pe, and photo minigames
    It's for the mission!

PROGRAMMBED BY:
    Ashana Rivera Monsanto

LAST MODIFIED:

VERSION:

ACKNOWLEDGEMENTS:
    Programming
        - w3schools
        - programiz
        - geeksforgeeks
        - stack overflow

    Art
        - asciiart
*/


#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
#endif


#include "Helpers/tools.c"
#include "Helpers/displayArt.c"
#include "Helpers/ui.c"
#include "Helpers/inputHandler.c"

#include "state.c"

#include "Sections/bond.c"
#include "Sections/math.c"

#include "gameLoop.c"

int main() {
    title();
    gameLoop();   
    // theEnd();
    return 0;
}