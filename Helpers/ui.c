/* determines which time to show on UI
    @TIME - used to decide if am nn pm
    @RETURN a text thats either morning, afternoon, or evening
*/
char *getTime(int TIME) { 
    switch(TIME) {
        case 0: return "Morning";
        case 1: return "Afternoon";
        case 2: return "Evening";
        default: return "N/A";
    }
}

/* shows the current day, time, and AP at the top part of the terminal
    @DAY - current day of the game
    @TIME - current time of the game
    @AP - current AP player has
*/
void ui(int DAY, int TIME) {
    printf("\n"
        "   Day %d\n"
        "   %s\n"
        "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n", 
        DAY, getTime(TIME)
    );
}


/* shows the current stats */
void viewStats(
    int AP,
	int VENUE, 
    int MATH, int PE, 
    int DAMIAN, int BECKY, int HENDERSON, int BOND,
    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
        printf(
            "\t\t\t\t\t\t\t============================================= Status =============================================\n\n"
            "\t\t\t\t\t\t\t\t\t    CURRENT AP\t\t\t    OUTING VENUE\n"
			"\t\t\t\t\t\t\t\t\t       - %d\t\t\t       - %s\n"
            "\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\t\t\t\t\t\t\t\t\t    SKILL LEVEL\n"
            "\t\t\t\t\t\t\t\t\t       - Math................%d\t       - PE..................%d\n"
            "\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\t\t\t\t\t\t\t\t\t    RELATIONSHIPS\n"
            "\t\t\t\t\t\t\t\t\t       - Damian..............%d\t       - Becky...............%d\n"
            "\t\t\t\t\t\t\t\t\t       - Mr. Henderson.......%d\t       - Bond................%d\n"
            "\t\t\t\t\t\t\t\t\t___________________________________________________________________\n\n"
            "\t\t\t\t\t\t\t\t\t    PHOTOGRAPHS\n"
            "\t\t\t\t\t\t\t\t\t       - Park......................................%s\n"
            "\t\t\t\t\t\t\t\t\t       - City Hall.................................%s\n"
            "\t\t\t\t\t\t\t\t\t       - Ostania Beach.............................%s\n",
            AP,
			getVenue(VENUE),
            MATH, PE, 
            DAMIAN, BECKY, HENDERSON, BOND,
            getRating(PH_1), getRating(PH_2), getRating(PH_3)
        );
        
        if(PH_4 > 0) printf("\t\t\t\t\t\t\t\t\t       - West Berlint Aquarium.....................%s\n", getRating(PH_4));
        if(PH_5 > 0) printf("\t\t\t\t\t\t\t\t\t       - Ostania Art Museum........................%s\n", getRating(PH_5));
        if(PH_6 > 0) printf("\t\t\t\t\t\t\t\t\t       - Berlint Mouseney Land.....................%s\n", getRating(PH_6));
        if(PH_7 > 0) printf("\t\t\t\t\t\t\t\t\t       - Park Avenue Dogland.......................%s\n", getRating(PH_7));
        
        printf("\n\t\t\t\t\t\t\t==================================================================================================\n\n");
}
