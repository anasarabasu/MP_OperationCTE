bool checkBP(int INPUT, int DAMIAN, int BECKY, int HENDERSON, int BOND) {
	switch(INPUT) {
		case 4:
			if(BECKY != 5) return false;
			else return true;
			break;
		case 5:
			if(HENDERSON != 5) return false;
			else return true;
			break;
		case 6:
			if(DAMIAN != 5) return false;
			else return true;
			break;
		case 7:
			if(BOND != 5) return false;
			else return true;
			break;
		default:
			return true;
	}
}

bool checkAP(int INPUT, int AP) {
	if(INPUT < 4 && AP == 0)
		return false;
	else 
		return true;
}

/* handles the input for the selection menus 
	@RETURNS the input once found valid
*/
int inputInt(
		int MAX,
		int SECTION, //0:outing    1:morning & afternoon select
	    int AP,
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
			viewStats(AP, VENUE, MATH, PE, DAMIAN, BECKY, HENDERSON, BOND, PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7);
		else {
			if(SECTION == 0 && checkBP(input, DAMIAN, BECKY, HENDERSON, BOND) == false) //outing selection
				returnInvalid();
			if(SECTION == 1 && checkAP(input, AP) == false) //morning activity selection
				lowAP();
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
