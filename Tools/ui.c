/* determines which time of the day to show on the UI
    PRECONDITION : must be valid [0 - 2]

    @TIME - used to decide if am nn pm

    @RETURN a text thats either morning, afternoon, or evening
*/
char *getTime(int TIME) { 
    switch(TIME) {
        case 0: return "Morning";
        case 1: return "Afternoon";
        case 2: return "Evening";
        default: return 0;
    }
}


/* shows the current day, time, and AP at the top section of the window
    PRECONDITION : must be non-negative

    @DAY - current day of the game
    @TIME - current time of the game
*/
void displayHeader(int DAY, int TIME) {
    printf("\n"
        "   Day %d\n"
        "\033[31m   %s\n"
        "\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n", 
        DAY, getTime(TIME)
    );
}


/* introduction scene of the game */
void introduction() { //henderson  talking about the exam and the project or something echeche
    //introArt();
    printf(
    	"\033[33m\t\t\t\t\t\t\t\t\t\t\t     I N T R O D U C T I O N\n"
    	"\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
        "\033[34m MR. HENDERSON : \033[0mLadies and gentlemen of Edn Academy, your attention, if I may....\n"
		"                 Each of you has been assigned an undertaking of considerabl educational value!\n\n"
		"\033[1;31m ANYA : \033[0mUh oh! Fancy teacher word means big homework!\033[30m >> PRESS ANY KEY TO CONTINUE"
	);
    #if defined(_WIN32) || defined(_WIN64) //this is annoying....
	    getch();
    #else 
        getchar();
    #endif

	printf(
		"\033[34m\n\n MR. HENDERSON : \033[0mYou are to create a photo college, one that captures meaningful moments spent among your perers and respective communities\n"
		"                 This collage must demonstrate the elegance befitting stuents of our esteemed insitution\n\n"
		"\033[1;31m ANYA : \033[0mElegance....?\033[30m >>"
	);
    #if defined(_WIN32) || defined(_WIN64)
	    getch();
    #else 
        getchar();
    #endif

	printf(
		"\033[34m\n\n MR. HENDERSON : \033[0mIn addition....\n"
		"                 I must remind you of the upcoming series of assessments, evaluating both your mathematical prowess\n"
		"                 and physical capabilities\n\n"
		"\033[1;31m ANYA : \033[0mMath AND Exercise!? This is double scary!\033[30m >>"
	);
    #if defined(_WIN32) || defined(_WIN64)
	    getch();
    #else 
        getchar();
    #endif

	printf(
		"\033[34m\n\n MR. HENDERSON : \033[0mYour performance in these examinations, combined with the quality of your collage, will determine which among you\n"
		"                 shall be deemed worthy of receiving a Stella Star\n\n"
		"\033[1;31m ANYA : \033[0m....But Stella Star means papa happy!\n"
		"        So Anya must! Try very! very! Hard!\033[30m >>"
	);
    #if defined(_WIN32) || defined(_WIN64)
	    getch();
    #else 
        getchar();
    #endif

	printf(
		"\033[34m\n\n MR. HENDERSON : \033[0mYou are allotted precisely 40 days to complete this project\n"
		"                 I expect all of you to approach this task with diligence, decorum, and above all....\n"
		"                 Elegance\n\n"
		"\033[1;31m ANYA : \033[0mForty days.... Okay!\n"
		"        Anya will make the most elegant collage ever!\n"
    );

    wipeScreen();
}


/* shows the values of important stats in the game
    PRECONDITION : must not be non-negative

    @AP - current activity points 
    @VENUE - current venue selected or N/A
    @MATH, PE - current skill level
    @DAMIAN, BECKY, HENDERSON, BOND - current bond level
    @PH_N - current rating or UNAVAILABLE
*/
void viewStats(
    int AP,
	int VENUE, 
    int MATH, int PE, 
    int DAMIAN, int BECKY, int HENDERSON, int BOND,
    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
        printf(
            "\t\t\t\t\t\t\t============================================= Status =============================================\n\n"
            "\033[31m\t\t\t\t\t\t\t\t\t    CURRENT AP\t\t\t    OUTING VENUE\n"
			"\033[0m\t\t\t\t\t\t\t\t\t       > %d\t\t\t       > %s\n"
            "\033[1;30m\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\033[33m\t\t\t\t\t\t\t\t\t    SKILL LEVEL\n"
            "\033[0m\t\t\t\t\t\t\t\t\t       > Math..............%s\t       > PE................%s\n"
            "\033[1;30m\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\033[32m\t\t\t\t\t\t\t\t\t    RELATIONSHIPS\n"
            "\033[0m\t\t\t\t\t\t\t\t\t       > Damian............%s\t       > Becky.............%s\n"
            "\t\t\t\t\t\t\t\t\t       > Mr. Henderson.....%s\t       > Bond..............%s\n"
            "\033[1;30m\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\033[36m\t\t\t\t\t\t\t\t\t    PHOTOGRAPHS\n"
            "\033[0m\t\t\t\t\t\t\t\t\t       > Park......................................%s\n"
            "\t\t\t\t\t\t\t\t\t       > City Hall.................................%s\n"
            "\t\t\t\t\t\t\t\t\t       > Ostania Beach.............................%s\n",
            AP,
			getVenue(VENUE),
            getNum(MATH, true), getNum(PE, true), 
            getNum(DAMIAN, false), getNum(BECKY, false), getNum(HENDERSON, false), getNum(BOND, false),
            getRating(PH_1), getRating(PH_2), getRating(PH_3)
        );
        
        if(PH_4 > 0) printf("\t\t\t\t\t\t\t\t\t       > West Berlint Aquarium.....................%s\n", getRating(PH_4));
        if(PH_5 > 0) printf("\t\t\t\t\t\t\t\t\t       > Ostania Art Museum........................%s\n", getRating(PH_5));
        if(PH_6 > 0) printf("\t\t\t\t\t\t\t\t\t       > Berlint Mouseney Land.....................%s\n", getRating(PH_6));
        if(PH_7 > 0) printf("\t\t\t\t\t\t\t\t\t       > Park Avenue Dogland.......................%s\n", getRating(PH_7));
        
        printf("\n\t\t\t\t\t\t\t==================================================================================================\n\n");
}


/* displays the actions for the morning section of the outing day */
void displayOutingMorningSelection() {
	printf(
		"\033[33m\t\t\t\t\t\t\t\t\t\t\t   O  U  T  I  N  G    D  A  Y\n"
		"\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		"\033[32m LOID : \033[0mAnya are you ready for the outing?\n"
		"\033[1;31m ANYA : \033[0mAnya will.... uhhhh....\n\n"
		"\033[36m\t[0] \033[0mView Stats\n"
		"\033[33m\t[1] \033[0mProceed with outing\n"
		"\033[33m\t[2] \033[0mStay home\n\n"
	);
}


/* displays the available venues to choose from
    PRECONDITION : must be non-negative

    @DAMIAN, BECKY, HENDERSON, BOND - current bond level that determines whether certain locations are unlocked

*/
void displayOutingVenueSelection(int DAMIAN, int BECKY, int HENDERSON, int BOND) {
    printf(
        "\033[33m\t\t\t\t\t\t\t\t\t\t   F  A  M  I  L  Y     M  E  E  T  I  N  G  !\n"
		"\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
        "\033[32m LOID : \033[0mAlright, Anya. Where would you like our outing venue to be?\n"
		"        Just choose whichever option you like best\n\n"
        "\033[1;31m ANYA : \033[0mUhhhh.... Ummmm....\n\n"
        "\033[31m YOR : \033[0mThese are some places that seem good to go to....\n\n"
        "\033[1;30m BOND : \033[0mBorf!\n\n"
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		"\033[1;31m ANYA : \033[0mHmmmm.... where should Anya go?\n\n"
		"\033[36m\t[0] \033[0mView Stats\n"
        "\033[33m\t[1] \033[0mPark\t\t\t"
        "\033[33m\t[2] \033[0mCity Mall\t\t\t"
        "\033[33m\t[3] \033[0mOstania Beach\n"
    );
    
    printf("\t%s", (BECKY == 5) ? "\033[33m[4] \033[0mWest Berlint Aquarium\t" : "\033[1;30m[X] LOCKED\033[0m\t\t\t");
    printf("\t%s", (HENDERSON == 5) ? "\033[33m[5] \033[0mOstania Art Museum\t\t" : "\033[1;30m[X] LOCKED\033[0m\t\t\t");
    printf("\t%s", (DAMIAN == 5) ? "\033[33m[6] \033[0mBerlint Mouseney Land\t\t" : "\033[1;30m[X] LOCKED\033[0m\t\t\t");
    printf("\t%s", (BOND == 5) ? "\033[33m[7] \033[0mPark Avenue Dogland\t\t" : "\033[1;30m[X] LOCKED\033[0m\t\t\t");

    printf("\n\n");
}


/* displays the morning activity to choose from */
void displayMorningSelection() {
	printf(
		"\033[33m\t\t\t\t\t\t\t\t\t\t\tE  D  E  N    A  C  A  D  E  M  Y\n"
		"\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		" %s\n\n"		
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"		
		"\033[1;31m ANYA : \033[0mUhhhh.... What should Anya do?\n\n"
		"\033[36m\t[0] \033[0mView Stats\n"
	    "\033[33m\t[1] \033[0mAnnoy Damian\t\t"
	    "\033[33m\t[2] \033[0mPlay with Becky\t\t"
	    "\033[33m\t[3] \033[0mTalk to Mr. Henderson\t\t"
	    "\033[33m\t[4] \033[0mGo home\n\n",
	    getSelectionMessage(1)
	);	
}


/* displays the afternoon activty to choose from */
void displayAfternoonSelection() {
    printf(
		"\033[33m\t\t\t\t\t\t\t\t\t\t\t\t    H  O  M  E\n"
		"\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
        "\033[31m YOR : \033[0mWelcome back, Anya! Were you safe today? No injuries? No suspicious people following you?\n\n"
        "\033[32m LOID : \033[0mWelcome home. How was school? Did anything.... noteworthy happen?\n\n"
        "\033[1;31m ANYA : \033[0mAh.... Finally home! Couch!\n\n"
        " %s\n\n"
	    "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		"\033[1;31m ANYA : \033[0mHmmmm.... What should Anya do?\n\n"
		"\033[36m\t[0] \033[0mView Stats\n"
        "\033[33m\t[1] \033[0mStudy with Loid\t\t"
        "\033[33m\t[2] \033[0mTrain with Yor\t\t"
        "\033[33m\t[3] \033[0mPlay with Bond\t\t"
        "\033[33m\t[4] \033[0mSlack off\n\n",
        getSelectionMessage(3)
    );
}


/* displays the instructions of the minigame*/
void displayInstructions(int INDEX) {
	switch(INDEX) {
		case 0: //math
			printf(
				"\t\t\t\t\t\t\t========================================== Instructions ==========================================\n\n"
				"\t\t\t\t\t\t\t\t\t    Try your best to guide Anya in her Math studies!\n\n"
				"\t\t\t\t\t\t\t\t\t    Your current Math Skill Level will determine the number, \n"
				"\t\t\t\t\t\t\t\t\t    type, and difficulty of the questions generated.\n\n"
                "\t\t\t\t\t\t\t\t\t    To answer, simply type in a number and hit enter.\n\n"
				//"\t\t\t\t\t\t\t\t\t    You have 30 seconds to enter your answer!\n\n"
				"\t\t\t\t\t\t\t=================================================================================================\n\n"
			);
			break;
		case 1: //pe
			printf(
				"\t\t\t\t\t\t\t========================================== Instructions ==========================================\n\n"
				"\t\t\t\t\t\t\t\t\t    Try your best to guide Anya in her PE studies!\n\n"
				"\t\t\t\t\t\t\t\t\t    Your current PE Skill Level will determine the number, \n"
				"\t\t\t\t\t\t\t\t\t    type, and difficulty of the prompts generated.\n\n"
                "\t\t\t\t\t\t\t\t\t    Key Guide:\n"
                "\033[0m\t\t\t\t\t\t\t\t\t    press \033[33m[ w | a | s | d ]\033[0m for axis directions.......\033[36mU L D R \n"
                "\033[0m\t\t\t\t\t\t\t\t\t    press \033[33m[ 8 | 4 | 2 | 6 ]\033[0m for cardinal directions...\033[36mN W E S\n"
                "\033[0m\t\t\t\t\t\t\t\t\t    press \033[33m[ W | A | S | D ]\033[0m for relative directions...\033[36mUA TTL BY TTR\n"
                "\033[0m\t\t\t\t\t\t\t\t\t    press \033[33m[ 7 | 9 | 1 | 3 ]\033[0m for ordinal directions....\033[36mNW NE SW SE\n\n"
                "\033[31m\t\t\t\t\t\t\t\t\t    [!] NO NEED TO HIT ENTER\n\n"
                "\t\t\t\t\t\t\t\t\t    [!] ENABLE NUM LOCK\n\n"
//				"\t\t\t\t\t\t\t\t\t    You have 30 seconds to enter your answer!\n\n"
				"\033[0m\t\t\t\t\t\t\t=================================================================================================\n\n"
			);
			break;
		case 2: //photo
			printf(
				"\t\t\t\t\t\t\t========================================== Instructions ==========================================\n\n"
				"\t\t\t\t\t\t\t\t\t    Try your best to guide Anya in taking photos!\n\n"
				"\t\t\t\t\t\t\t\t\t    You have to guess the special number from 1-1000\n"
				"\t\t\t\t\t\t\t\t\t    Your number of attempts depend on your current AP and \n"
				"\t\t\t\t\t\t\t\t\t    camera rolls\n\n"
                "\t\t\t\t\t\t\t\t\t    Rating Guide:\n"
                "\033[31m\t\t\t\t\t\t\t\t\t    NOT GOOD....Too far of range\n"
                "\033[0m\t\t\t\t\t\t\t\t\t    OKAY........Within a range of 100 from the special number\n"
                "\033[33m\t\t\t\t\t\t\t\t\t    VERY GOOD...Within a range of 10 from the special number\n"
                "\033[32m\t\t\t\t\t\t\t\t\t    PERFECT.....Exactly the special number \n\n"
				"\t\t\t\t\t\t\t=================================================================================================\n\n"
			);
			break;
	}
}
