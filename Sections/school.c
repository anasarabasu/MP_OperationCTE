void displayMorningSelection() {
	printf(
	    "\t[0] View Stats\n"
	    "\t[1] Annoy Damian\t\t"
	    "\t[2] Play with Becky\t\t"
	    "\t[3] Talk to Mr. Henderson\t\t"
	    "\t[4] Go home\n\n"
	);	
}

/*----------------------------------------
    @LEVEL 
    @CHANCE
    @RETURNS
*/
void gainBP(int LEVEL, int CHANCE, int *BP, int *AP) {
    if(*BP < 5) {
        if(LEVEL == 1) CHANCE *= 0;
        //level == 2 is default chance val
        if(LEVEL == 3) CHANCE += 25;
        if(LEVEL == 4) CHANCE += 50;
        
        if(rng(100, 0) < CHANCE) {
            printf("Whooo");
            *BP++;
        }
        else {
        	printf("meh");
		}
        *AP--;
    }
    else if (rng(100, 0) < 50) { //max BP bonus chance
        *AP += 2;
    }
}

void bondingActivity(
		int ACTIVITY, int *AP,
		int *DAMIAN, int PE,
		int *BECKY,
		int *HENDERSON, int MATH,
		int *BOND
		) {
    switch(ACTIVITY) {
        case 1:
        	printf("Dami");
            gainBP(PE, 25, DAMIAN, AP);
            break;
        case 2:
        	printf("Becky");
            gainBP(0, 75, BECKY, AP);
            break;
        case 3:
        	printf("Hender");
            gainBP(MATH, 50, HENDERSON, AP);
            break;
    }
}
//
//
//
//void afternoon_ActivitySelection() {}
//
//void schoolEvening() {}