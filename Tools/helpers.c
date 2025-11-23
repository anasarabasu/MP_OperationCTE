/* waits for key press before proceeding */
void awaitInput() {
    printf("\n\033[30m------------------------------------------------------------------------------------------> \033[33mPRESS ANY KEY TO CONTINUE\033[30m <------------------------------------------------------------------------------------------\033[0m \n");
	getch();
}


/* clears the screen to move onto the next scene */
void wipeScreen() {
    printf("\n\033[1;30m------------------------------------------------------------------------------------------> \033[33mPRESS ANY KEY TO CONTINUE\033[1;30m <------------------------------------------------------------------------------------------\033[0m \n");
    
	getch();
	CLEAR_SCREEN();
}


/* modification of the wipeScreen which displays AP change */
void endDay(int DAY, int *AP) {
	printf("\n\033[1;30m------------------------------------------------------------------------------------------> \033[33mPRESS ANY KEY TO CONTINUE\033[1;30m <------------------------------------------------------------------------------------------\033[0m \n");
   
   
	getch();
	
	printf("[ DAY END ]");
	
	if(DAY < 40) {
	    if(DAY % 4 == 0) {
	    	if(*AP <= 3) {
				*AP =  3;
				printf("\033[32m [ AP RESET TO 3 ]");
			} 
			else printf(" [ AP UNCHANGED ]");
		}
	    else if(DAY % 3 != 0) {
			(*AP)++;
	    	printf("\033[32m [ +1 AP ]");
		}
		else printf(" [ AP UNCHANGED ]");	
	}
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
    
    printf(" \033[1;31mANYA : \033[0m ");
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
				return "\033[33mMAX\033[0m";
			else
				return "..4";
    	case 5: return "\033[33mMAX\033[0m";
    	default: return 0;
	}
}


/* RETURN the rating string based on the INDEX */
char *getRating(int INDEX) {
    switch(INDEX) {
        case 1: return "NOT GOOD";
        case 2: return "OKAY";
        case 3: return "VERY GOOD";
        case 4: return "\033[33mPERFECT\033[0m";
        default: return "\033[31mN/A\033[0m\t";
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

/* RETURN a randomised message */
char *getSelectionMessage(int INDEX) {
	switch(rng(3, 0) + INDEX) {
		//1
		case 0: return "\033[32m LOID : \033[0mAnya, remember to behave properly at school today\n\n \033[1;31m ANYA : \033[0m Okay! Anya will do her best.... probably";
		case 1: return "\033[31m YOR : \033[0mGood luck, Anya! I hope you have a safe and peaceful day!\n\n \033[1;31m ANYA : \033[0m Mama, Anya will survive!";
		case 2: return "\033[1;30m BOND : \033[0mBorf!\n\n\033[1;31m ANYA : \033[0m Bond can't come to school, but Anya will tell him everything later!";
		
		//2
		case 3: return "\033[1;30m BOND : \033[0mBorf!";
		case 4: return "\033[31m YOR : \033[0mW-wait, Anya! Maybe.... not at a full sprint toward the couch? You might get hurt!";
		case 5: return "\033[32m LOID : \033[0mMaybe.... slow down a little?";

		default:  return 0;
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
        "\033[1;30m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\033[0m \n\n"
		" \033[1;31m ANYA : \033[0m Huff.... Anya is tired!\n\n"
		" >> Anya achieved an overall score of %d%%\n", percent
	);

	//fail
	if(percent < 60) {
		(*AP)--;
		printf(" [ +0 EXP ]\033[31m [ -1 AP ]\n\n");

		//math
		if(SKILL == 0)
			printf(
				" \033[32m LOID : \033[0mThis.... is not good Anya....\n"
				" \033[1;31m ANYA : \033[0m Um! Anya promises to do better next time papa!\n"
			);
		//pe
		else
			printf(
				" \033[31m YOR : \033[0mOh no.... I'm sure Miss Anya will do better next time!\n"
				" \033[1;31m ANYA : \033[0m Yes! Anya promises mama!\n"
			);
	}

	//mediocre
	else if(percent < 80) {
		(*EXP)++;
		(*AP)--;
		printf("\033[33m [ +1 EXP ]\033[31m [ -1 AP ]\n\n");

		//math
		if(SKILL == 0)
			printf(
				" \033[32m LOID : \033[0mWell.... It's not bad\n"
				" \033[1;31m ANYA : \033[0m Yay-\n"
				" \033[32m LOID : \033[0mBut it's not good either....\n"
				" \033[1;31m ANYA : \033[0m .... Anya promises to do better next time papa!\n"
			);
		//pe
		else
			printf(
				" \033[31m YOR : \033[0mMiss Anya did all right!\n"
				" \033[1;31m ANYA : \033[0m Yay-\n"
				" \033[31m YOR : \033[0mBut, hmmmm.... I think you can do better!\n"
				" \033[1;31m ANYA : \033[0m .... Anya promises to do better next time mama!\n"
			);
	}
	
	//good
	else if(percent < 100) {
		*EXP += 2;
		(*AP)--;
		printf("\033[33m [ +2 EXP ]\033[31m [ -1 AP ]\n\n");

		//math
		if(SKILL == 0) printf(" \033[32m LOID : \033[0mGood job Anya! You did well!\n");

		//pe
		else printf(" \033[31m YOR : \033[0mGood job Miss Anya! You got most of it right!\n");
			
		printf(" \033[1;31m ANYA : \033[0m .... Anya will keep up!\n");
	}

	//perfect
	else {
		if(*EXP >= 30) { //equivalent to max math level
			if (rng(100, 0) < 60) {
				*AP += 2;
				printf("\033[33m [ MAX LEVEL ]\033[32m [ +2 AP BONUS ]\n\n");
				
				//math
				if(SKILL == 0) printf(" \033[32m LOID : \033[0mWell done, Anya! You've mastered math!\n");
				
				//pe
				else printf(" \033[31m YOR : \033[0mCongratulations Mis Anya! You've masterd PE!\n");
			}
			printf(" \033[1;31m ANYA : \033[0m Yay! I’m amazing!\n");
		}
		else {
			*EXP += 3;
			if(rng(100, 0) < 50) { //ap consumption chance
				(*AP)--;
				printf("\033[33m [ +3 EXP ]\033[32m [ +1 AP BONUS ]\n\n");
			}
			else {
				(*AP)++;
				printf("\033[33m [ +3 EXP ]\033[31m [ -1 AP ]\n\n");
			}
			//math
			if(SKILL == 0) printf(" \033[32m LOID : \033[0mWell done Anya! You got everything correct!\n");
			
			//pe
			else printf(" YOR: Wow! Miss Anya got everything right!\n");
			
			printf(" \033[1;31m ANYA : \033[0m Yahoo!\n");
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
				"\033[34m [ LEVEL UP ]\n"
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


char *getEndingThoughts(int INDEX, int CHAR) {
	switch(INDEX + CHAR) {
		//anya
		case 1: return "Confident! Yay!";
		case 2: return "Okay....? Maybe?";
		case 3: return "S-scared.... Ehehe";

		//henderson
		case 4: return "Not bad.... let's see how it turns out";
		case 5: return "Hm.... quite something, I suppose";
		case 6: return "Hmmmm.... we'll have to think about this";
		
		default: return 0;
	}
}


char *getEndingBanner(int INDEX) {
	switch(INDEX) {
		case 1: return "\033[32m\t\t\t\t\t\t\t\t\t\t     P  E  R  F  E  C  T    E  N  D  I  N  G\n";
		case 2: return "\033[33m\t\t\t\t\t\t\t\t\t\t\t    O  K     E  N  D  I  N  G\n";
		case 3: return "\033[31m\t\t\t\t\t\t\t\t\t\t\t   B  A  D    E  N  D  I  N  G\n";
		default: return 0;
	}
}
