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


int *getVenueMem(
		int VENUE,
		int *M1, int *M2, int *M3, int *M4, int *M5, int *M6, int*M7) {
	switch(VENUE) {
        case 1: return M1;
        case 2: return M2;
        case 3: return M3;
        case 4: return M4;
        case 5: return M5;
        case 6: return M6;
        case 7: return M7;
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
	photoArt(*GUESS_MEMORY);
	
    bool isFinish = false;
	
	int rating;
    int camRolls = 5;

	int input;
	
	printf(
		" ANYA : Time to take some photos!\n"
		" ANYA : Is Anya ready?\n\n"
		"\t[Y] Yes\t\t\t\t[N] No, view instructions\n\n >> "
	);
	
	scanf(" %c", &input);
	
	if((char) tolower(input) == 'y')
		printf(" ANYA : Yes! Anya will take the best photos!\n");
	else if((char) tolower(input) == 'n') {
		printf(" ANYA : Ummmm.... What will Anya do again? Hehe\n");
		displayInstructions(2);
		printf(" ANYA : Yes! Anya will take the best photos!\n");
	}
	else {	
		printf(
			" ANYA : Uhhhh....?\n\n"
			" ANYA : Anya should probably do something like this....\n"
		);
		displayInstructions(2);
		printf(" ANYA : Anya will take the best photos!\n");
	} 
	
	awaitInput();
	
	int attempt = 1;
    do{
    	printf(
			"\n ATTEMPT %d\t\tREMAINING CAMERA ROLLS: %d\t\tCURRENT AP: %d\n\n" 
			" ANYA : Camera goes....\n"
			" [ 1 - 1000 ] >> ", attempt, camRolls, *AP
		);

        while(scanf(" %d", &input) != 1) {
            returnInvalid();

            printf(
				" ANYA : Uhhhh.... Let's try this again!\n"
				" ANYA : Camera goes!\n"
				" [ 1 - 1000 ] >> "
			);
        }

		printf(
			" ANYA : Click!\n\n"
			" >> Your photo rating is....\n"
		);
        if(input == KEY) {
            isFinish = true;
            rating = 4;
            
            printf(
				" [ PERFECT ]\n\n"
				" ANYA : Wow! wow!\n\n"
			);
        }
        else if(input <= KEY + 10 && input >= KEY - 10) {
            if(rating <= 3) rating = 3;
            
            printf(
            	" [ VERY GOOD ]\n\n"
				" ANYA : Looks good! Just a bit to the....um...."
			);
			if(input > KEY) printf("left?\n\n");
            if(input < KEY) printf("right?\n\n");
        }
        else if(input <= KEY + 100 && input >= KEY - 100) {
            if(rating <= 2) rating = 2;
            
            printf(
            	" [ OKAY ]\n\n"
				" ANYA : Okay.... maybe a little bit to the....Hmmmm...."
			);
            if(input > KEY) printf("left?\n\n");
            if(input < KEY) printf("right?\n\n");
        }
        else if(input == 464646) {
            rating = 4;
            isFinish = true;

    		printf("cheater lmao\n\n");
        }
        else {
        	if(rating <= 1) rating = 1;
            printf(
            	" [ NOT GOOD ]\n\n"
				" ANYA : Ah! That is way too far off....\n\n"
			);
        }
        rememberInput(input, GUESS_MEMORY, KEY);
        
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
        camRolls--;
        (*AP)--;
        attempt++;
    	
    }
    while(camRolls > 0 && *AP > 0 && !isFinish);
    
    printf(
		"\t\t\t\t\t\t\t\t\t\t\t\tF  I  N  I  S  H !\n"
        "-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
	);
	if(isFinish) {
		printf(
			" ANYA : Anya took super good photo! Heh-heh!\n"
			" YOR : Oh my— that’s amazing, Anya! You're really talented!\n\n"
			" LOID : Impressive work. You captured the moment perfectly.... well done, Anya\n"
			" >> Guessed the special number perfectly!\n"
		);
	}
	else {
	
	    if(*AP == 0) printf(" ANYA : Huff! Anya is tired!\n\n");
	    else if(camRolls == 0) printf(" ANYA : Ah! Anya ran out of camera rolls!\n\n");
	
		printf(
			" LOID : Good job, Anya\n"
			" ANYA : But! Anya wants MORE photos! For mission....\n"
			" YOR : Ah.... um.... M-Miss Anya, maybe you should rest a bit? We can take more another time\n"
			" ANYA : Okayyyy....\n\n"
			" >> The guess closest to the special numer is %d\n", 
			*GUESS_MEMORY
		);
	}

    return rating;
}