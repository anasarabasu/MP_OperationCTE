int generateVenueKey() {
    int key = rng(1000, 1);
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


void rememberInput(int GUESS, int *STORED_GUESS, int KEY) {
	int distanceCurrent = abs(KEY - GUESS);
	int distanceStored = abs(KEY - *STORED_GUESS);
	
	if(distanceCurrent < distanceStored) 
		*STORED_GUESS = GUESS;
}


int startPhotoMini(int VENUE, int KEY, int *GUESS_MEMORY, int *AP) {
    bool isFinish = false;
	
	int rating;
    int camRolls = 5;
    
    printf("%d", KEY);
    printf("Best Guess: %d\n", *GUESS_MEMORY);

    printf("Guess!\n");
    do{
		int input;

        while(scanf(" %d", &input) != 1) {
            returnInvalid();

            printf(" ANYA : Uhhhh.... Let's try this again!\n");
            printf(" >> ");
        }

        if(input == KEY) {
            isFinish = true;
            rating = 4;
            
            printf("PERFECT\n");
        }
        else if(input <= KEY + 10 && input >= KEY - 10) {
            if(rating <= 3) rating = 3;
            printf("Looks good! Just an inch closer\n");
        }
        else if(input <= KEY + 100 && input >= KEY - 100) {
            if(rating <= 2) rating = 2;
            printf("Okay.... maybe a little bit to the left\n");
        }
        else if(input == 464646) {
            rating = 4;
            isFinish = true;

    		printf("cheater lmao\n");
        }
        else {
        	if(rating == 1) rating = 1;
            printf("That is way too far off....\n");
        }
        
        rememberInput(input, GUESS_MEMORY, KEY);
        camRolls--;
        (*AP)--;
		printf("%d\n", *AP);
    }
    while(camRolls > 0 && *AP > 0 && !isFinish);
    
    printf("Best Guess: %d\n", *GUESS_MEMORY);
    
    if(camRolls == 0)
    	printf(" ANYA : Ah! Anya ran out of camera rolls!\n");
    if(*AP == 0)
    	printf(" ANYA : Huff! Anya is tired!\n");

    return rating;
}