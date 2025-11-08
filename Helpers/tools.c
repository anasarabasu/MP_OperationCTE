/* clears the screen to move onto the next scene */
void wipeScreen() {
    printf("\n\n------------------------------------------------------------------------------------------> PRESS ANY KEY TO CONTINUE <------------------------------------------------------------------------------------------\n");
    
    #if defined(_WIN32) || defined(_WIN64)
    getch();
    system("cls");
    
	#else
	getchar();
	system("clear");
	
	#endif
}


/* randomiser
	@MAX - sets the range of the randomiser
	@OFFSET - whether to ofset the random selection
	
	@RETURN a randomly generated number
*/
int rng(int MAX, int OFFSET) {
    int random = rand() % MAX + OFFSET;
    return random;
}


/* display message for invalid output */
void returnInvalid() {
    scanf("%*[^\n]"); 
    getchar();
    
    printf(" ANYA : ");
    switch(rng(4, 0)) {
        case 0:
            printf("Huuuuh?");
            break;
        case 1:
            printf("Um?");
            break;
        case 2:
            printf("....");
            break;
        case 3:
            printf("Anya doesn't think that's right....");
            break;
    }
    printf("\n\n");
}


void lowAP() {
    printf(" ANYA : ");
    switch(rng(4, 0)) {
        case 0:
            printf("Anya wants to sleep!");
            break;
        case 1:
            printf("Hmmmmmmmmm.... Noooo....");
            break;
        case 2:
            printf("Ughhhhhhh....");
            break;
        case 3:
            printf("No! Anya doesn't wanna!");
            break;
    }
    printf("\n\n");
}


char *getVenue(int INDEX) {
    switch(INDEX) {
        case 1: return "Park";
        case 2: return "City Mall";
        case 3: return "Ostania Beach";
        case 4: return "West Berlint Aquarium";
        case 5: return "Ostania Art Museum";
        case 6: return "Berlint Mouseney Land";
        case 7: return "Park Avenue Dogland";
        default: return "N/A";
    }
}


char *getRating(int INDEX) {
    switch(INDEX) {
        case 1: return "NOT GOOD";
        case 2: return "OKAY";
        case 3: return "VERY GOOD";
        case 4: return "PERFECT";
        default: return "N/A\t";
    }
}


char *getActivity(int INDEX) {
    switch(INDEX) {
        case 1: return "Annoy Damian!";
        case 2: return "Play with Becky!";
        case 3: return "Talk to Mr. Henderson!";
        case 4: return "Go home!";
    }
    return 0;
}

char *getName(int INDEX) {
    switch(INDEX) {
        case 1: return "Damian";
        case 2: return "Becky";
        case 3: return "Mr. Henderson";
        default: return "Bond";
    }
}

char *maxBondMessage(int INDEX) {
    switch(INDEX) {
        case 1: 
            return " DAMIAN : DAMIAN: Hmph… you're not completely hopeless, I suppose. If you insist, I guess we could go to Mouseney Land—just don't expect me to hold back my superiority.";
        case 2: 
            return " BECKY : Yayyy! It's decided! We're going to the aquarium, and it's going to be soooo much fun—I can already see the penguins!";
        case 3: 
            return " MR. HENDERSON : My, what refinement you've displayed. Perhaps a visit to the Ostania Art Museum would provide a most suitable enrichment for your talents.";
        default: 
            return " BOND : Borf!\n LOID : Haha… looks like Bond's ready for a little adventure at Dogland!";
    }
}

char *bondingTip(int SUCCEED, int INDEX) {
    if(SUCCEED) 
        switch(INDEX) {
            case 1:
                return " DAMIAN: Hmph… not bad. You actually managed to keep up. I suppose I can tolerate your efforts a little more.\n ANYA : Hehe! Take that, Sy-on-boy! Don't get too proud!";
            case 2:
                return " BECKY : Ahaha! That was so much fun! Let's do this again sometime!\n ANYA : Yosh! Let's play again next time!";
            case 3:
                return " HENDERSON : Excellent work! Your performance shows considerable refinement. Truly admirable.\n ANYA : Yahooo! That was fun, even if he said boring stuff....";
            default:
                return " BOND : Borf! *wags tail*\n YOR: Hmmm… Bond seems very pleased! Maybe miss Anya can try again later and keep this up!\n ANYA : Hehe! Bond likes me!";
        }
    else
        switch(INDEX) {
            case 1:
                return " DAMIAN : Hmph… you might want to focus on improving your PE skills first. Do try to keep up.\n ANYA : Huuhh! Meanie! Does Sy-on boy wanna get punched again?";
            case 2:
                return " BECKY : Hehe! Sorry, I'm not quite up for it right now… but let's try this again soon!\n ANYA : Okay… Next time we'll make it super fun!";
            case 3:
                return " HENDERSON : My, perhaps honing your math skills would be a most prudent endeavor before progressing further.\n ANYA : I don't wanna go to school anymore....";
            default:
                return " BOND : Borf!\n YOR : Hmmm.... Bond doesn't seem to be in the mood today. Maybe miss Anya can try again next time?\n ANYA : Okay mama....";
        }
}