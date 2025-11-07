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
void ui(int DAY, int TIME, int AP) {
    if(DAY != 0) {
        printf("\n"
            "   Day %d\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t AP: %d\n"
            "   %s\n"
            "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n", 
            DAY, AP, getTime(TIME)
        );
    }
    else {
        printf("\n"
            "   Day %d\n"
            "   %s\n"
            "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n", 
            DAY, getTime(TIME)
        );

    }
}


/* shows the current stats */
void viewStats(
    int VENUE, 
    int MATH, int PE, 
    int DAMIAN, int BECKY, int HENDERSON, int BOND,
    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
        printf(
            "\t============================= Status =============================\n\n"
            "\t    VENUE FOR OUTING\n"
            "\t       - %s\n\n"
            "\t    SKILL LEVEL\n"
            "\t       - Math.........................................%d\n"
            "\t       - PE...........................................%d\n\n"
            "\t    RELATIONSHIPS\n"
            "\t       - Damian.......................................%d\n"
            "\t       - Becky........................................%d\n"
            "\t       - Mr. Henderson................................%d\n"
            "\t       - Bond.........................................%d\n\n"
            "\t    PHOTOGRAPHS\n"
            "\t       - Park......................................%s\n"
            "\t       - City Hall.................................%s\n"
            "\t       - Ostania Beach.............................%s\n",
            getVenue(VENUE),
            MATH, PE, 
            DAMIAN, BECKY, HENDERSON, BOND,
            getRating(PH_1), getRating(PH_2), getRating(PH_3)
        );
        
        if(PH_4 > 0) printf("\t║       - West Berlint Aquarium.....................%s\n", getRating(PH_4));
        if(PH_5 > 0) printf("\t║       - Ostania Art Museum........................%s\n", getRating(PH_5));
        if(PH_6 > 0) printf("\t║       - Berlint Mouseney Land.....................%s\n", getRating(PH_6));
        if(PH_7 > 0) printf("\t║       - Park Avenue Dogland.......................%s\n", getRating(PH_7));
        
        printf("\n\t==================================================================\n\n");
}
