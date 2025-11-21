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
        "   %s\n"
        "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n", 
        DAY, getTime(TIME)
    );
}


/* introduction scene of the game */
void introduction() { //henderson  talking about the exam and the project or something echeche
    //introArt();
    printf(
    	"\t\t\t\t\t\t\t\t\t\t\t     I N T R O D U C T I O N\n"
    	"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
        " MR. HENDERSON : Ladies and gentlemen of Edn Academy, your attention, if I may....\n"
		"                 Each of you has been assigned an undertaking of considerabl educational value!\n\n"
		" ANYA : Uh oh! Fancy teacher word means big homework!\n"
		" >> PRESS ANY KEY TO CONTINUE"
	);
	getch();
	printf(
		"\n\n MR. HENDERSON : You are to create a photo college, one that captures meaningful moments spent among your perers and respective communities\n"
		"                 This collage must demonstrate the elegance befitting stuents of our esteemed insitution\n\n"
		" ANYA : Elegance....?\n"
		" >>"
	);
	getch();
	printf(
		"\n\n MR. HENDERSON : In addition....\n"
		"                 I must remind you of the upcoming series of assessments, evaluating both your mathematical prowess\n"
		"                 and physical capabilities\n\n"
		" ANYA : Math AND Exercise!? This is double scary!\n"
		" >>"
	);
	getch();
	printf(
		"\n\n MR. HENDERSON : Your performance in these examinations, combined with the quality of your collage, will determine which among you\n"
		"                 shall be deemed worthy of receiving a Stella Star\n\n"
		" ANYA : ....But Stella Star means papa happy!\n"
		"        So Anya must! Try very! very! Hard!\n"
		" >>"
	);
	getch();
	printf(
		"\n\n MR. HENDERSON : You are allotted precisely 40 days to complete this project\n"
		"                 I expect all of you to approach this task with diligence, decorum, and above all....\n"
		"                 Elegance\n\n"
		" ANYA : Forty days.... Okay!\n"
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
            "\t\t\t\t\t\t\t\t\t    CURRENT AP\t\t\t    OUTING VENUE\n"
			"\t\t\t\t\t\t\t\t\t       > %d\t\t\t       > %s\n"
            "\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\t\t\t\t\t\t\t\t\t    SKILL LEVEL\n"
            "\t\t\t\t\t\t\t\t\t       > Math..............%s\t       > PE................%s\n"
            "\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\t\t\t\t\t\t\t\t\t    RELATIONSHIPS\n"
            "\t\t\t\t\t\t\t\t\t       > Damian............%s\t       > Becky.............%s\n"
            "\t\t\t\t\t\t\t\t\t       > Mr. Henderson.....%s\t       > Bond..............%s\n"
            "\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\t\t\t\t\t\t\t\t\t    PHOTOGRAPHS\n"
            "\t\t\t\t\t\t\t\t\t       > Park......................................%s\n"
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
		"\t\t\t\t\t\t\t\t\t\t\t   O  U  T  I  N  G    D  A  Y\n"
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		" LOID : Anya are you ready for the outing?\n"
		" ANYA : Anya will.... uhhhh....\n\n"
		"\t[0] View Stats\n"
		"\t[1] Proceed with outing\n"
		"\t[2] Stay home\n\n"
	);
}


/* displays the available venues to choose from
    PRECONDITION : must be non-negative

    @DAMIAN, BECKY, HENDERSON, BOND - current bond level that determines whether certain locations are unlocked

*/
void displayOutingVenueSelection(int DAMIAN, int BECKY, int HENDERSON, int BOND) {
    printf(
        "\t\t\t\t\t\t\t\t\t\t   F  A  M  I  L  Y     M  E  E  T  I  N  G  !\n"
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
        " LOID : Alright, Anya. Where would you like our outing venue to be?\n"
		"        Just choose whichever option you like best\n\n"
        " ANYA : Uhhhh.... Ummmm....\n\n"
        " YOR : These are some places that seem good to go to....\n\n"
        " BOND : Borf!\n\n"
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		" ANYA : Hmmmm.... where should Anya go?\n\n"
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


/* displays the morning activity to choose from */
void displayMorningSelection() {
	printf(
		"\t\t\t\t\t\t\t\t\t\t\tE  D  E  N    A  C  A  D  E  M  Y\n"
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		" %s\n\n"		
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"		
		" ANYA : Uhhhh.... What should Anya do?\n\n"
		"\t[0] View Stats\n"
	    "\t[1] Annoy Damian\t\t"
	    "\t[2] Play with Becky\t\t"
	    "\t[3] Talk to Mr. Henderson\t\t"
	    "\t[4] Go home\n\n",
	    getSelectionMessage(1)
	);	
}


/* displays the afternoon activty to choose from */
void displayAfternoonSelection() {
    printf(
		"\t\t\t\t\t\t\t\t\t\t\t\t    H  O  M  E\n"
		"-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
        " YOR : Welcome back, Anya! Were you safe today? No injuries? No suspicious people following you?\n\n"
        " LOID : Welcome home. How was school? Did anything.... noteworthy happen?\n\n"
        " ANYA : Ah.... Finally home! Couch!\n\n"
        " %s\n\n"
	    "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		" ANYA : Hmmmm.... What should Anya do?\n\n"
		"\t[0] View Stats\n"
        "\t[1] Study with Loid\t\t"
        "\t[2] Train with Yor\t\t"
        "\t[3] Play with Bond\t\t"
        "\t[4] Slack off\n\n",
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
                "\t\t\t\t\t\t\t\t\t    press [ w | a | s | d ] for axis directions.......U L D R \n"
                "\t\t\t\t\t\t\t\t\t    press [ 8 | 4 | 2 | 6 ] for cardinal directions...N W E S\n"
                "\t\t\t\t\t\t\t\t\t    press [ W | A | S | D ] for relative directions...UA TTL BY TTR\n"
                "\t\t\t\t\t\t\t\t\t    press [ 7 | 9 | 1 | 3 ] for ordinal directions....NW NE SW SE\n\n"
                "\t\t\t\t\t\t\t\t\t    [!] NO NEED TO HIT ENTER\n\n"
                "\t\t\t\t\t\t\t\t\t    [!] ENABLE NUM LOCK\n\n"
//				"\t\t\t\t\t\t\t\t\t    You have 30 seconds to enter your answer!\n\n"
				"\t\t\t\t\t\t\t=================================================================================================\n\n"
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
                "\t\t\t\t\t\t\t\t\t    NOT GOOD....Too far of range\n"
                "\t\t\t\t\t\t\t\t\t    OKAY........Within a range of 100 from the special number\n"
                "\t\t\t\t\t\t\t\t\t    VERY GOOD...Within a range of 10 from the special number\n"
                "\t\t\t\t\t\t\t\t\t    PERFECT.....Exactly the special number \n\n"
				"\t\t\t\t\t\t\t=================================================================================================\n\n"
			);
			break;
	}
}
