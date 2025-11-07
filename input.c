bool checkBP(int INPUT, int DAMIAN, int BECKY, int HENDERSON, int BOND) {
	switch(INPUT) {
		case 4:
			if(DAMIAN != 4) 
			return 1;
		case 5:
			if(BECKY != 4) 
			return 1;
		case 6:
			if(HENDERSON != 4) 
			return 1;
		case 7:
			if(BOND != 4) 
			return 1;
		default:
			return 0;
	}
}

/* handles the input for the selection menus 
	@RETURNS the input once found valid
*/
int inputInt(
		int SECTION, //0: outing
		int MAX,
		int VENUE,
		int MATH, int PE,
		int DAMIAN, int BECKY, int HENDERSON, int BOND, 
	    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7
		) {
	int input;
	do {
		printf(" >> ");
		
		if(scanf("%d", &input) != 1) //not a number
			returnInvalid();
		else if(input < 0 || input > MAX) //number but not in range
				returnInvalid();
		else if(input == 0) //access stats
			viewStats(VENUE, MATH, PE, DAMIAN, BECKY, HENDERSON, BOND, PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7);
		else { //custom conditional
			if(SECTION == 0 && checkBP(input, DAMIAN, BECKY, HENDERSON, BOND) == 1) //outing selection
				returnInvalid();
			}
		}
	while(
		input <= 0 || 
		input > MAX || 
		input == 4 && DAMIAN != 4 || 
		input == 5 && BECKY != 4 || 
		input == 6 && HENDERSON != 4 || 
		input == 7 && BOND != 4);
	
	return input;
}

//char inputChar() {
//	char input;
//	do {
//		printf(" >> ");
//	}
//	while 
//	
//	return input;
//}