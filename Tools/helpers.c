/* waits for key press before proceeding */
void awaitInput() {
    printf("\n------------------------------------------------------------------------------------------> PRESS ANY KEY TO CONTINUE <------------------------------------------------------------------------------------------\n");
    
    //this is here for cross compatibility testing because im on linux :)
    #if defined(_WIN32) || defined(_WIN64)
	getch();
    
	#else
	getchar();
	
	#endif
}


/* clears the screen to move onto the next scene */
void wipeScreen() {
    printf("\n------------------------------------------------------------------------------------------> PRESS ANY KEY TO CONTINUE <------------------------------------------------------------------------------------------\n");
    
    //this is here for cross compatibility testing because im on linux :)
    #if defined(_WIN32) || defined(_WIN64)
	getch();
	system("cls");
    
	#else
	getchar();
	system("clear");
	
	#endif
}


/* modification of the wipeScreen which displays AP change */
void endDay(int DAY, int *AP) {
	printf("\n------------------------------------------------------------------------------------------> PRESS ANY KEY TO CONTINUE <------------------------------------------------------------------------------------------\n");
   
    //this is here for cross compatibility testing because im on linux :)
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
		(*AP)++;
    	printf(" [ +1 AP ]");
	}
	else printf(" [ AP UNCHANGED ]");	
	
	printf("\n");
	
	wipeScreen();
}


/* random number generator
    PRECONDITION : must be non-negative values

	@MAX - sets the range of the randomiser
	@OFFSET - sets the offset of the random selection
	
	@RETURN a randomly generated number
*/
int rng(int MAX, int OFFSET) {
    int random = rand() % MAX + OFFSET;
    return random;
}


/* display message for invalid input */
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


/* RETURN the venue string based on the INDEX */
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


/* RETURN the number string based on the INDEX */
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


/* RETURN the rating string based on the INDEX */
char *getRating(int INDEX) {
    switch(INDEX) {
        case 1: return "NOT GOOD";
        case 2: return "OKAY";
        case 3: return "VERY GOOD";
        case 4: return "PERFECT";
        default: return "N/A\t";
    }
}


/* RETURN the activity string based on the INDEX */
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
        case 9: return "Go to the ooting!";
        case 10: return "Stay home.... Anya is tired....";
        default: return 0;
    }
}


/* RETURN the name string based on the INDEX */
char *getName(int INDEX) {
    switch(INDEX) {
        case 1: return "Damian";
        case 2: return "Becky";
        case 3: return "Mr. Henderson";
        case 4: return "Bond";
        default: return 0;
    }
}


/* RETURN the number of questions based on the current skill LVLV*/
int getTotal(int LVL) {
	if(LVL == 1) return 5;
	else return 10;
}


/* ends the mini by displaying the score total, level-up status, and the stat changes 
	determines how much EXP is gained, as well as the chance of the bonus reward

	PRECONDITION 
		- must be non-negative
		- SKILL must be a valid value [0 or 1]

	@SCORE - score achieved during the minigame
	@TOTAL - total questions based on the math level
	@AP - pointer to AP
	@EXP - pointer to EXP
	@SKILL - determines to display math or pe specific messages

*/
void finishMini(int SCORE, int TOTAL, int *AP, int *EXP, int SKILL) {
	int percent = SCORE * 100 / TOTAL;
	printf(
		"\t\t\t\t\t\t\t\t\t\t\t\tF  I  N  I  S  H !\n"
        "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		" ANYA : Huff.... Anya is tired!\n\n"
		" >> Anya achieved an overall score of %d%%\n", percent
	);

	//fail
	if(percent < 60) {
		(*AP)--;
		printf(" [ +0 EXP ] [ -1 AP ]\n\n");

		//math
		if(SKILL == 0)
			printf(
				" LOID : This.... is not good Anya....\n"
				" ANYA : Um! Anya promises to do better next time papa!\n"
			);
		//pe
		else
			printf(
				" YOR : Oh no.... I'm sure Miss Anya will do better next time!\n"
				" ANYA : Yes! Anya promises mama!\n"
			);
	}

	//mediocre
	else if(percent < 80) {
		(*EXP)++;
		(*AP)--;
		printf(" [ +1 EXP ] [ -1 AP ]\n\n");

		//math
		if(SKILL == 0)
			printf(
				" LOID : Well.... It's not bad\n"
				" ANYA : Yay-\n"
				" LOID : But it's not good either....\n"
				" ANYA : .... Anya promises to do better next time papa!\n"
			);
		//pe
		else
			printf(
				" YOR : Miss Anya did all right!\n"
				" ANYA : Yay-\n"
				" YOR : But, hmmmm.... I think you can do better!\n"
				" ANYA : .... Anya promises to do better next time mama!\n"
			);
	}
	
	//good
	else if(percent < 100) {
		*EXP += 2;
		(*AP)--;
		printf(" [ +2 EXP ] [ -1 AP ]\n\n");

		//math
		if(SKILL == 0) printf(" LOID : Good job Anya! You did well!\n");

		//pe
		else printf(" YOR : Good job Miss Anya! You most of it right!\n");
			
		printf(" ANYA : .... Anya will keep up!\n");
	}

	//perfect
	else {
		if(*EXP >= 30) { //equivalent to max math level
			if (rng(100, 0) < 60) {
				*AP += 2;
				printf(" [ MAX LEVEL ] [ +2 AP BONUS ]\n\n");
				
				//math
				if(SKILL == 0) printf(" LOID : Well done, Anya! You've mastered math!\n");
				
				//pe
				else printf(" YOR : Congratulations Mis Anya! You've masterd PE!\n");
			}
			printf(" ANYA : Yay! I’m amazing!\n");
		}
		else {
			*EXP += 3;
			if(rng(100, 0) < 50) { //ap consumption chance
				(*AP)--;
				printf(" [ +3 EXP ] [ +1 AP BONUS ]\n\n");
			}
			else {
				(*AP)++;
				printf(" [ +3 EXP ] [ -1 AP ]\n\n");
			}
			//math
			if(SKILL == 0) printf(" LOID : Well done Anya! You got everything correct!\n");
			
			//pe
			else printf(" YOR: Wow! Miss Anya got everything right!\n");
			
			printf(" ANYA : Yahoo!\n");
		}
	}
}


/* determines whether to increase the chosen skill level
	PRECONDITION : must be a non-negative value

	@LVL - pointer to chosen skill
	@EXP - current skill exp
*/
void levelUp(int *LVL, int EXP) {
	printf("\n");
	
	//lvl 1
	if(EXP < 5) printf(" >> Anya needs %d more to get to the next level", 5-EXP);

	//lvl 2
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

	//lvl 3
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

	//lvl max
	else if(EXP >= 30) {
		if(*LVL == 3) {
			printf(" [ LEVEL UP ]\n");
			*LVL = 4; 
		}
		printf(" >> Anya has reached the max level!");
	}
		
	printf("\n");
}