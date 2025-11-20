/* checks the current bond points, used for venue selection
	PRECONDITION 
		- must be non-negative values
		- INPUT must be a valid value [4 - 7]

	@INPUT - current user input
	@DAMIAN, BECKY, HENDERSON, BOND

	@RETURN a bool about the input's validity
*/
bool checkBP(int INPUT, int DAMIAN, int BECKY, int HENDERSON, int BOND) {
	switch(INPUT) {
		case 4:
			if(BECKY != 5) return false;
			else return true;
		case 5:
			if(HENDERSON != 5) return false;
			else return true;
		case 6:
			if(DAMIAN != 5) return false;
			else return true;
		case 7:
			if(BOND != 5) return false;
			else return true;
		default:
			return true;
	}
}


/* checks the current AP, used for the activity selection
	PRECONDITION
		- must be non-negative values
		- INPUT must be a valid value [0 - 3]

	@INPUT - current user input
	@AP - current AP

	@RETURN a bool about the input's validity
*/
bool checkAP(int INPUT, int AP) {
	if(INPUT < 4 && AP == 0) return false;
	else return true;
}


/* displays message for low AP */
void lowAP() {
    printf(" ANYA : ");
    switch(rng(4, 0)) {
        case 0:
            printf("Anya wants to sleep!");
            break;
        case 1:
            printf("Hmmmm.... Noooo....");
            break;
        case 2:
            printf("Ughhhh....");
            break;
        case 3:
            printf("No! Anya doesn't wanna!");
            break;
    }
    printf("\n\n");
}


/* handles the user input for the selection prompt
	PRECONDITION
		- must be non-negative values
		- must be valid values [MAX > 0] [SECTION is 0 or 1]

	@MAX - max range of int input
	@SECTION - determines if its an outing or school selection

	-- these are for displaying the stat variables among other stuff --
		@AP
		@VENUE
		@MATH, PE
		@DAMIAN, BECKY, HENDERSON, BOND
		@PH_N

	@RETURNS the input once found valid
*/
int checkSelection(
		int MAX,
		int SECTION, //0:outing    1:morning & afternoon select
	    int AP,
		int VENUE,
		int MATH, int PE,
		int DAMIAN, int BECKY, int HENDERSON, int BOND, 
	    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
	int input;
	do {
		printf(" >> ");
		
		//not a number
		if(scanf(" %d", &input) != 1) returnInvalid();
			
		//number but not in range
		else if(input < 0 || input > MAX) returnInvalid();

		//access stats
		else if(input == 0) viewStats(AP, VENUE, MATH, PE, DAMIAN, BECKY, HENDERSON, BOND, PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7);

		//section-specific conditions
		else { 
			//outing venue election
			if(SECTION == 0 && checkBP(input, DAMIAN, BECKY, HENDERSON, BOND) == false) returnInvalid();

			//school activity selection
			if(SECTION == 1 && checkAP(input, AP) == false) lowAP();
		}
	}
	while(
		input <= 0 || 
		input > MAX || 
		(SECTION == 0 && checkBP(input, DAMIAN, BECKY, HENDERSON, BOND) == false) ||
		(SECTION == 1 && checkAP(input, AP) == false)
	);
	
	return input;
}