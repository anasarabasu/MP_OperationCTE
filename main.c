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

#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

//this is here for cross compatibility testing because im on linux :)
#if defined(_WIN32) || defined(_WIN64)
    #include <conio.h>
#endif


#include "Tools/helpers.c"
#include "Tools/displayArt.c"
#include "Tools/ui.c"
#include "Tools/selection.c"

#include "Sections/bond.c"
#include "Sections/math.c"
#include "Sections/pe.c"
#include "Sections/photo.c"

#include "state.c"

int main() {
	srand(time(NULL)); //i noticed that randomly generated numbers are the same across several runs, this should fix it
	
    title();
    gameLoop();   
    // theEnd();

    return 0;
}