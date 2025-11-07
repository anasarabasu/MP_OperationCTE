/*  */
void outingMorning(int VENUE) {
}


/*  */
void outingAfternoon(int VENUE) {

}


/* displays a dynamic status of the venues 
    @DAMIAN - value of current bond points which will determine its unlocked state 
    @BECKY - "
    #HENDERSON - "
    @BOND - "
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