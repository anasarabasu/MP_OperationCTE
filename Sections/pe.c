char generatePrompt(int LVL) {
	int random = 4;
	if(LVL == 2) random = 8;
	if(LVL >= 3) random = 16;

	switch(rng(random, 0)) {
		//lvl 1
		case 0: 
			printf("Up!"); //whats this FNF? lmao
			return 'w';
		case 1: 
			printf("Left!");
			return 'a';
		case 2: 
			printf("Down!");
			return 's';
		case 3: 
			printf("Right!");
			return 'd';

		//lvl 2
		case 4: 
			printf("North!");
			return '8';
		case 5: 
			printf("West!");
			return '4';
		case 6: 
			printf("South!");
			return '2';
		case 7: 
			printf("East!");
			return '6';

		//lvl 3
		case 8: 
			printf("UP AHEAD!");
			return 'W';
		case 9: 
			printf("TO THE LEFT!");
			return 'A';
		case 10: 
			printf("BEHIND YOU!");
			return 'S';
		case 11: 
			printf("TO THE RIGHT!");
			return 'D';
		case 12: 
			printf("North-west!");
			return '7';
		case 13: 
			printf("North-east!");
			return '9';
		case 14: 
			printf("South-west!");
			return '1';
		case 15: 
			printf("South-east!");
			return '3';
	}
	return 0;
}

bool checkPrompt(char INPUT, char PROMPT, int LVL) {
	char input = INPUT;
	if(LVL < 3) 
		input = (char) tolower(INPUT); //because i dont wanna type the a || A thing lol
		// if(INPUT >= 65 && INPUT <= 90) input += 32; //caveman syntax lololol

	if(input == PROMPT) return true;
	else return false;
}


int startPEMini(int LVL) {
	peArt(LVL);
	
	int score = 0;
	int totalPrompts = getTotal(LVL);

	char input;

	printf(
		" YOR : Miss Anya, I have %d things for you to do. Are you ready?\n\n"
		"\t[Y] Yes\t\t\t\t[N] No, view instructions\n\n >> ",
		totalPrompts
	);
	
	scanf(" %c", &input);
	if((char) tolower(input) == 'y')
		printf(" ANYA : Anya will give it her all mama!\n");
	else if((char) tolower(input) == 'n') {
		printf(" ANYA : Ummmm.... What will Anya do again? Hehe\n");
		displayInstructions(1);
		printf(" ANYA : Anya will give it her all mama!\n");
	}
	else {	
		printf(
			" ANYA : Uhhhh....?\n\n"
			" YOR : Huh?\n"
			" YOR : O-oh! Um.... I’m guessing you’d like the instructions?\n"
		);
		displayInstructions(1);
		printf(" ANYA : Anya will give it her all mama!\n");
	} 
	
	awaitInput();
	
	int promptIndex = 1;
	do {
		char prompt; 
		
		printf(
			"\n PROMPT %d\n\n"
			" YOR : ",
			promptIndex
		);
		prompt = generatePrompt(LVL);

		printf("\n >> ");    	
		#if defined(_WIN32) || defined(_WIN64)
		input = getche();
		#else
		scanf(" %c", &input);
		#endif

		printf("\n\n YOR : ");
		if(checkPrompt(input, prompt, LVL)) {
			printf(
				"Good job!\n"
				" ANYA : Anya is doing great at PE!\n\n"
			);
			score++;
		}
		else if(input == '!') { //godmode
    		printf("cheater lmao\n\n");
    		score += 5;
		}
		else {
			printf(
				"Oh no! Miss Anya that's not the right direction!\n"
				" ANYA :  AH! Anya got confused!\n\n"
			);
		}
		printf("-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n");
		promptIndex++;
	}
	while(promptIndex <= totalPrompts);
	
	return score;
}