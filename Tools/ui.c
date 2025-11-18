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
        "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n", 
        DAY, getTime(TIME)
    );
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


/* displays the available venues to choose from
    PRECONDITION : must be non-negative

    @DAMIAN, BECKY, HENDERSON, BOND - current bond level that determines whether certain locations are unlocked

*/
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


/* displays the morning activity to choose from */
void displayMorningSelection() {
	printf(
	    "\t[0] View Stats\n"
	    "\t[1] Annoy Damian\t\t"
	    "\t[2] Play with Becky\t\t"
	    "\t[3] Talk to Mr. Henderson\t\t"
	    "\t[4] Go home\n\n"
	);	
}


/* displays the afternoon activty to choose from */
void displayAfternoonSelection() {
    printf(
	    "\t[0] View Stats\n"
        "\t[1] Study with Loid\t\t"
        "\t[2] Train with Yor\t\t"
        "\t[3] Play with Bond\t\t"
        "\t[4] Slack off\n\n"
    );
}