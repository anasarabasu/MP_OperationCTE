/*-----------------------------------------
*/
void outingMorning(int VENUE) {
}


/*-----------------------------------------------
*/
void outingAfternoon(int VENUE) {

}


/*--------------------------------------------------
displays the status of the venues 
    @UNLOCKED - the number of venues available to choose
*/
void displayVenues(int DAMIAN, int BECKY, int HENDERSON, int BOND) {
    printf(
        "\t[0] View Stats\n"
        "\t[1] Park\t\t\t"
        "\t[2] City Mall\t\t\t"
        "\t[3] Ostania Beach\n"
    );
    
    printf("\t%s", (BECKY == 4) ? "[4] West Berlint Aquarium\t" : "[X] Locked\t\t\t");
    printf("\t%s", (HENDERSON == 4) ? "[5] Ostania Art Museum\t\t" : "[X] Locked\t\t\t");
    printf("\t%s", (DAMIAN == 4) ? "[6] Berlint Mouseney Land\t\t" : "[X] Locked\t\t\t");
    printf("\t%s", (BOND == 4) ? "[7] Park Avenue Dogland\t\t" : "[X] Locked\t\t\t");
}


/*---------------------------------------------
*/
void evening_OutingSelection(
    int *currentVenue,
    int MATH, int PE, 
    int DAMIAN, int BECKY, int HENDERSON, int BOND, 
    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
        displayVenues(DAMIAN, BECKY, HENDERSON, BOND);
        printf("\n\nwhere to go?\n\n");
        
        int input;
        do {
            printf(" >>> ");
            if(scanf("%d", &input) != 1) 
                returnInvalid(); //not a number
            else { //is a number
                if(input < 0 || input > 7) returnInvalid(); //is a number but out of range
                else if(input == 4 && BECKY != 4 || input == 5 && HENDERSON != 4 || input == 6 && DAMIAN != 4 || input == 7 && BOND != 4) returnInvalid(); //in range but locked
                else if(input == 0) viewStats(input, MATH, PE, DAMIAN, BECKY, HENDERSON, BOND, PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7);
                
            }
        }
        while(input <= 0 || input > 7 || input == 4 && BECKY != 4 || input == 5 && HENDERSON != 4 || input == 6 && DAMIAN != 4 || input == 7 && BOND != 4);
        
        printf(" Anya decided she wants to go to the.... %s\n",getVenue(input));

        *currentVenue = input;
}