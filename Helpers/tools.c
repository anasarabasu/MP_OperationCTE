/* clears the screen to move onto the next scene */
void wipeScreen() {
    printf("\n------------------------------------------------------------------------------------------> PRESS ANY KEY TO CONTINUE <------------------------------------------------------------------------------------------\n");
    
    #if defined(_WIN32) || defined(_WIN64)
    getch();
    system("cls");
    
	#else
	getchar();
	system("clear");
	
	#endif
}


void endDay(int DAY, int *AP) {
	printf("\n------------------------------------------------------------------------------------------> PRESS ANY KEY TO CONTINUE <------------------------------------------------------------------------------------------\n");
   
    #if defined(_WIN32) || defined(_WIN64)
    getch();
    
	#else
	getchar();
	
	#endif
	
	printf("\n [ DAY END ]"
		);
    if(DAY % 4 == 0) {
    	if(*AP <= 3) {
			*AP =  3;
			printf(" [ AP RESET TO 3 ]");
		} 
		else printf(" [ AP UNCHANGED ]");
	}
    else if(DAY % 3 != 0) {
		*AP++;
    	printf(" [ +1 AP ]");
	}
	else printf(" [ AP UNCHANGED ]");	
	
	printf("\n");
	
	//maybe add a randomised text? lol
	wipeScreen();
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
            printf("Anya is confused....");
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


void displayOutingSelection(int DAMIAN, int BECKY, int HENDERSON, int BOND) {
    printf(
        "\t[0] View Stats\n"
        "\t[1] Park\t\t\t"
        "\t[2] City Mall\t\t\t"
        "\t[3] Ostania Beach\n"
    );
    
    printf("\t%s", (BECKY == 5) ? "[4] West Berlint Aquarium\t" : "[X] LOCKED\t\t\t");
    printf("\t%s", (HENDERSON == 5) ? "[5] Ostania Art Museum\t\t" : "[X] LOCKED\t\t\t");
    printf("\t%s", (DAMIAN == 5) ? "[6] Berlint Mouseney Land\t\t" : "[X] LOCKED\t\t\t");
    printf("\t%s", (BOND == 5) ? "[7] Park Avenue Dogland\t\t" : "[X] LOCKED\t\t\t");

    printf("\n\n");
}


void displayMorningSelection() {
	printf(
	    "\t[0] View Stats\n"
	    "\t[1] Annoy Damian\t\t"
	    "\t[2] Play with Becky\t\t"
	    "\t[3] Talk to Mr. Henderson\t\t"
	    "\t[4] Go home\n\n"
	);	
}


void displayAfternoonSelection() {
    printf(
	    "\t[0] View Stats\n"
        "\t[1] Study with Loid\t\t"
        "\t[2] Train with Yor\t\t"
        "\t[3] Play with Bond\t\t"
        "\t[4] Slack off\n\n"
    );
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


char *getNum(int NUM, bool IS_SKILL) {
	switch(NUM) {
		case 0: return "..0";
		case 1: return "..1";
		case 2: return "..2";
		case 3: return "..3";
		case 4: 
			if(IS_SKILL)
				return "MAX";
			else
				return "..4";
    	case 5: return "MAX";
    	default: return 0;
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
        case 1: return "Annoy Damian";
        case 2: return "Play with Becky";
        case 3: return "Talk to Mr. Henderson";
        case 4: return "Go home";
        case 5: return "Study with papa";
        case 6: return "Train with mama";
        case 7: return "Play with Bond";
        case 8: return "Slack off";
        default: return 0;
    }
}


char *getName(int INDEX) {
    switch(INDEX) {
        case 1: return "Damian";
        case 2: return "Becky";
        case 3: return "Mr. Henderson";
        case 4: return "Bond";
        default: return 0;
    }
}


char *maxBondMessage(int INDEX) {
    switch(INDEX) {
        case 1: 
            return " DAMIAN : DAMIAN: Hmph.... you're not completely hopeless, I suppose. I guess I can introduce you to Mouseney Land. You might enjoy it there....";
        case 2: 
            return " BECKY : Hey! I think you'll like it there at the West Berlint Aquarium! There's penguins!";
        case 3: 
            return " MR. HENDERSON : My, what such elegance you've displayed! Perhaps a visit to the Ostania Art Museum would provide a most suitable enrichment for your talents.";
        case 4: 
            return " BOND : Borf!\n LOID : Haha.... looks like Bond's ready for a little adventure at Dogland!";
        default: return 0;
    }
}


char *bondingTip(bool SUCCEED, int INDEX) {
    if(SUCCEED) 
        switch(INDEX) {
            case 1:
                return " DAMIAN: Hmph.... not bad. You actually managed to keep up. I suppose I can tolerate your efforts a little more.\n ANYA : Hehe! Take that, Sy-on-boy! Don't get too proud!";
            case 2:
                return " BECKY : Ahaha! That was so much fun! Let's do this again sometime!\n ANYA : Yosh! Let's play again next time!";
            case 3:
                return " HENDERSON : Excellent work! Your performance shows considerable refinement. Truly admirable.\n ANYA : Yahooo! That was fun, even if he said boring stuff....";
            case 4:
                return " BOND : Borf! *wags tail*\n YOR: Hmmm... Bond seems very pleased! Maybe miss Anya can try again later and keep this up!\n ANYA : Hehe! Bond likes me mama!";
            default: return 0;
        }
    else
        switch(INDEX) {
            case 1:
                return " DAMIAN : Hmph.... you might want to focus on improving your PE skills first. Do try to keep up.\n ANYA : Huuhh! Meanie! Does Sy-on boy wanna get punched again?";
            case 2:
                return " BECKY : Hehe! Sorry, I'm not quite up for it right now.... but let's try this again soon!\n ANYA : Okay.... Next time we'll make it super fun!";
            case 3:
                return " HENDERSON : My, perhaps honing your math skills would be a most prudent endeavor before progressing further.\n ANYA : I don't wanna go to school anymore....";
            case 4:
                return " BOND : Borf!\n YOR : Hmmm.... Bond doesn't seem to be in the mood today. Maybe miss Anya can try again next time?\n ANYA : Okay mama....";
            default: return 0;
        }
}


char *mathQuestion(int OPERATION, int INDEX) {
	switch(OPERATION) {
		case 0: //add
			switch(INDEX) {
				case 0: return "What would you get if you add %d and %d?";
				case 1: return "%d and %d combined is?";
				case 2: return "What is %d + %d?";
				case 3: return "The sum of %d and %d is?";
			}
			break;
		case 1: //sub
			switch(INDEX) {
				case 0: return "What would you get if you subtract %d and %d?";
				case 1: return "%d subtracted by %d is?";
				case 2: return "What is %d - %d?";
				case 3: return "The difference of %d and %d?";
			}
			break;
		case 2: //mul
			switch(INDEX) {
				case 0: return "What would you get if you multiply %d and %d?";
				case 1: return "%d multiplied by %d is?";
				case 2: return "What is %d x %d?";
				case 3: return "The product of %d and %d?";
			}
			break;
		default: return 0;
	}
}

void levelUp(int *LVL, int EXP) {
	printf("\n");
	
	if(EXP < 5) 
		printf(" >> Anya needs %d more to get to the next level", 5-EXP);
	else if(EXP < 15) {
		if(*LVL == 1) {
			printf(
				" [ LEVEL UP ]\n"
				" >> Anya's is now level 2!\n"
			);
			*LVL = 2;
		}
		printf(" >> Anya needs %d more to get to the next level", 15-EXP);
	}
	else if(EXP < 30) {
		if(*LVL == 2) {
			printf(
				" [ LEVEL UP ]\n"
				" >> Anya's is now level 3!\n"
			);
			*LVL = 3;
		}
		printf(" >> Anya needs %d more to get to the next level", 30-EXP);
	}
	else if(EXP >= 30) {
		if(*LVL == 3) {
			printf(" [ LEVEL UP ]\n");
			*LVL = 4; 
		}
		printf(" >> Anya has reached the max level!");
	}
		
	printf("\n");
}