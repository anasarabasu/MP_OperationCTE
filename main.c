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
#include <conio.h>

#include "Helpers/tools.c"
#include "Helpers/art.c"
#include "Helpers/ui.c"
#include "input.c"

#include "state.c"

#include "Sections/outing.c"
//#include "Sections/school.c"

#include "gameLoop.c"


int main() {
    title();
    gameLoop();   
    // theEnd();
    return 0;
}