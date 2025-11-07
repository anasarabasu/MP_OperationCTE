/*----------------------------------------------------
displays the title screen
*/
void title() {
    titleArt();
    wipeScreen();
}


/*------------------------------------
introduction scene of the game
*/
void introduction() { //henderson  talking about the exam and the project or something echeche
    introArt();
    
    printf(
        "Mr. Henderson: blah blah blah do this do that ELEGANCE\n math math pe assessment\n\n"
    );

    wipeScreen();
}


/*---------------------------------------
*/
void viewStats(
    int VENUE, 
    int MATH, int PE, 
    int DAMIAN, int BECKY, int HENDERSON, int BOND,
    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
        printf(
            "\t╔════════════════════════════ Status ═══════════════════════════╗\n"
            "\t║                                                               ║\n"
            "\t║    VENUE FOR OUTING                                           ║\n"
            "\t║       - %s\t\t\t\t\t║\n"
            "\t║                                                               ║\n"
            "\t║    SKILL LEVEL                                                ║\n"
            "\t║       - Math.........................................%d\t║\n"
            "\t║       - PE...........................................%d\t║\n"
            "\t║                                                               ║\n"
            "\t║    RELATIONSHIPS                                              ║\n"
            "\t║       - Damian.......................................%d\t║\n"
            "\t║       - Becky........................................%d\t║\n"
            "\t║       - Mr. Henderson................................%d\t║\n"
            "\t║       - Bond.........................................%d\t║\n"
            "\t║                                                               ║\n"
            "\t║    PHOTOGRAPHS                                                ║\n"
            "\t║       - Park....................................%s\t║\n"
            "\t║       - City Hall...............................%s\t║\n"
            "\t║       - Ostania Beach...........................%s\t║\n",
            getVenue(VENUE),
            MATH, PE, 
            DAMIAN, BECKY, HENDERSON, BOND,
            getRating(PH_1), getRating(PH_2), getRating(PH_3)
        );
        
        if(PH_4 > 0) printf("\t║       - West Berlint Aquarium...................%s\t║\n", getRating(PH_4));
        if(PH_5 > 0) printf("\t║       - Ostania Art Museum......................%s\t║\n", getRating(PH_5));
        if(PH_6 > 0) printf("\t║       - Berlint Mouseney Land...................%s\t║\n", getRating(PH_6));
        if(PH_7 > 0) printf("\t║       - Park Avenue Dogland.....................%s\t║\n", getRating(PH_7));
        
        printf(
            "\t║                                                               ║\n"
            "\t╚═══════════════════════════════════════════════════════════════╝\n\n"
        );
}


/*---------------------------------------------
*/
void theEnd() {}


