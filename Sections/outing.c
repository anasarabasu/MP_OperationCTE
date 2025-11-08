// /*  */
// void outingMorning(int VENUE) {
// }


// /*  */
// void outingAfternoon(int VENUE) {

// }


/* displays a dynamic status of the venues 
    @DAMIAN - value of current bond points which will determine its unlocked state 
    @BECKY - "
    #HENDERSON - "
    @BOND - "
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
}