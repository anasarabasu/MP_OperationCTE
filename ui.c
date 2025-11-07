/*----------------------------------------------------
determines which day to show on UI
    @DAY - used to decide if outing or reg day

    @RETURN a text thats either ooting or school day
*/
char *getDay(int DAY) {
    if(DAY != 0) {
        if(DAY % 4 == 0)
            return "Ooting day!";
        else
            return "School day!";
    }
    return "Introduction";
}


/*---------------------------------------------------------------
determines which time to show on UI
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


/*----------------------------------------------------
the ui that shows the current day, time, and AP
    @DAY - current day of the game
    @TIME - current time of the game
    @AP - current AP player has
*/
void ui(int DAY, int TIME, int AP) {
    if(DAY != 0) {
        printf("\n"
            "    Day %d - %s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\tAP: %d\n"
            "    %s\n"
            "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n", 
            DAY, getDay(DAY), AP, getTime(TIME)
        );
    }
    else {
        printf("\n"
            "    Day %d - %s\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\t\n"
            "    %s\n"
            "------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n", 
            DAY, getDay(DAY), getTime(TIME)
        );

    }
}