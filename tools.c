int rng(int MAX, int OFFSET) {
    int random = rand() % MAX + OFFSET;
    return random;
}

/*
make a list of sassy remarks for invalid inputs lmao
*/
void returnInvalid() {
    scanf("%*[^\n]"); 
    getchar();
    
    printf(" ANYA : ");
    switch(rng(4, 0)) {
        case 0:
            printf("Huuuuh?");
            break;
        case 1:
            printf("Um?");
            break;
        case 2:
            printf("....");
            break;
        case 3:
            printf("Anya doesn't think that's right....");
            break;
    }
    printf("\n\n");
}

void lowAP() {
    printf(" ANYA : ");
    switch(rng(4, 0)) {
        case 0:
            printf("Anya wants to sleep!");
            break;
        case 1:
            printf("Hmmmmmmmmm.... Noooo....");
            break;
        case 2:
            printf("Ughhhhhhh....");
            break;
        case 3:
            printf("No! Anya doesn't wanna!");
            break;
    }
    printf("\n\n");
}

char *getVenue(int VENUE_INDEX) {
    switch(VENUE_INDEX) {
        case 1: return "Park!\t\t";
        case 2: return "City Mall!\t";
        case 3: return "Ostania Beach!\t";
        case 4: return "West Berlint Aquarium!";
        case 5: return "Ostania Art Museum!";
        case 6: return "Berlint Mouseney Land!";
        case 7: return "Park Avenue Dogland!";
        default: return "N/A\t\t";
    }
}

char *getRating(int RATING_INDEX) {
    switch(RATING_INDEX) {
        case 1: return "NOT GOOD";
        case 2: return "OKAY";
        case 3: return "VERY GOOD";
        case 4: return "PERFECT";
        default: return "N/A\t";
    }
}

char *getActivity(int ACTIVITY_INDEX) {
    switch(ACTIVITY_INDEX) {
        case 1: return "Annoy Damian!";
        case 2: return "Play with Becky!";
        case 3: return "Talk to Mr. Henderson!";
        case 4: return "Go home!";
    }
}

void wipeScreen() {
    printf("                                                                                             > PRESS ANY KEY TO CONTINUE <                                                                                              \n");
    getchar();
    system("clear");
}