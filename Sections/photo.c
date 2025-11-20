int generateVenueKey() {
    int key = rng(1000, 1);

    printf("%d\n", key);

    return key;
}

int *getVenueRating(
        int VENUE,
        int *V1, int *V2, int *V3, int *V4, int *V5, int *V6, int *V7) {
    switch(VENUE) {
        case 1: return V1;
        case 2: return V2;
        case 3: return V3;
        case 4: return V4;
        case 5: return V5;
        case 6: return V6;
        case 7: return V7;
        default: return 0;

    }
}


int getVenueKey(
        int VENUE, 
        int K1, int K2, int K3, int K4, int K5, int K6, int K7) {
    switch(VENUE) {
        case 1: return K1;
        case 2: return K2;
        case 3: return K3;
        case 4: return K4;
        case 5: return K5;
        case 6: return K6;
        case 7: return K7;
        default: return 0;
    }
}

int startPhotoMini(int VENUE, int KEY, int *AP) {
    int rating;
    int camRolls = 5;

    printf("Guess!");
    do{
        int input;

        while(scanf(" %d", &input) != 1) {
            returnInvalid();

            printf(" ANYA : Uhhhh.... Let's try this again!\n");
            printf(" >> ");
        }

        if(input == KEY) {
            rating = 4;
            printf("PERFECT");
        }
        else if(input > KEY + 10 || input < KEY - 10) {
            rating = 3;
            printf("v good");
        }
        else if(input > KEY + 100 || input < KEY - 100) {
            rating = 2;
            printf("okay");
        }
        else if(input == 464646) {
            rating = 4;
            camRolls = 0;

    		printf("cheater lmao\n");
        }
        else {
            rating = 1;
            printf("eh");
        }

        camRolls--;
        (*AP)--;
    }
    while(camRolls > 0 || *AP > 0);

    return rating;
}