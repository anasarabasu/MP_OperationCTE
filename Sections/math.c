/* RETURN the math problem message string based on the OPERATION*/
char *mathQuestion(int OPERATION) {
	switch(OPERATION) {
		case 0: //add
			switch(rng(4, 0)) { 
				case 0: return "What would you get if you add %d and %d?";
				case 1: return "%d and %d combined is?";
				case 2: return "What is %d + %d?";
				case 3: return "The sum of %d and %d is?";
			}
			break;
		case 1: //sub
			switch(rng(4, 0)) {
				case 0: return "What would you get if you subtract %d and %d?";
				case 1: return "%d minus %d is?";
				case 2: return "What is %d - %d?";
				case 3: return "The difference of %d and %d?";
			}
			break;
		case 2: //mul
			switch(rng(4, 0)) {
				case 0: return "What would you get if you multiply %d and %d?";
				case 1: return "%d multiplied by %d is?";
				case 2: return "What is %d x %d?";
				case 3: return "The product of %d and %d?";
			}
			break;
    }
    return 0;
}


/* to "even it out" because the rng prefers to pick mostly 3 digits poor Anya :( */
int balanceRange(int RANGE) {
	return rng(RANGE % (int)pow(10, rng(3, 1)), 1);
}


/* the math minigame
	numbers are randomly generated based on the current math level
	math operations are also dependent on the math level

	PRECONDITION : must be non-negative

	@LVL - current math level

	@RETURN the score achieved during the minigame
*/
int startMathMini(int LVL) {
	mathArt(LVL);

	int score = 0;
    int totalQuestions = getTotal(LVL);
	int rangeAddSub, rangeMul;
    
    switch(LVL) { //return the num range
        case 1:
            rangeAddSub = 999;
            break;
        case 2: 
            rangeAddSub = 9999;
            rangeMul = 20;
            break;
		default: //for lvls 3 & 4(MAX)
            rangeAddSub = 9999;
			rangeMul = 50;
            break;
    }

    int operationUnlocked = 2;
    if(LVL > 1) operationUnlocked = 3;
    
    int input;
    
    printf(
		" \033[32m LOID : \033[0mAlright Anya, I'm going to ask you %d questions. Are you ready?\n\n"
		"\033[32m\t[Y] Yes\t\t\t\t\033[31m[N]\033[0m No, view instructions\n\n >> ",
		totalQuestions
	);
	
	scanf(" %c", &input);
	
	if((char) tolower(input) == 'y')
		printf("\033[1;31m ANYA : \033[0m Yes! Anya will do her best papa!\n");
	else if((char) tolower(input) == 'n') {
		printf("\033[1;31m ANYA : \033[0m Ummmm.... What will Anya do again? Hehe\n");
		displayInstructions(0);
		printf("\033[1;31m ANYA : \033[0m Yes! Anya will do her best papa!\n");
	}
	else {	
		printf(
			"\033[1;31m ANYA : \033[0m Uhhhh....?\n\n"
			"\033[32m LOID : \033[0mHuh?\n"
			"\033[32m LOID : \033[0mI’ll take it that you’re asking for instructions\n"
		);
		displayInstructions(0);
		printf("\033[1;31m ANYA : \033[0m Yes! Anya will do her best papa!\n");
	} 
	
	awaitInput();
	scanf("%*[^\n]"); 
    getchar();
	
    int questionIndex = 1;
	do {
        int x, y, answer;
        int operation = rng(operationUnlocked, 0);    
        
        printf(
			"\n QUESTION %d\n\n"
			"\033[32m LOID : \033[0m", 
			questionIndex
		);
        switch(operation) {   
            case 0: //addition
                x = balanceRange(rangeAddSub);
                y = balanceRange(rangeAddSub);
                answer = x + y;

                printf(mathQuestion(operation), x, y);
                break;
            case 1: //subtraction
                x = balanceRange(rangeAddSub);
                y = balanceRange(rangeAddSub);
                answer = x - y;
                
                printf(mathQuestion(operation), x, y);
                break;
            case 2: //multiplication
                x = rng(rangeMul, 1);
                y = rng(rangeMul, 1);
                answer = x * y;
                                
                printf(mathQuestion(operation), x, y);
                break;
        }

        printf("\n\n >> ");
        
		while(scanf("%d", &input) != 1) { //user input is not a number
    		returnInvalid(); 

			printf("\033[32m LOID : \033[0mThat doesn't seem right let's try again\n \033[32mLOID : \033[0m");
			printf(mathQuestion(operation), x, y);
    		printf("\n\n >> ");
		}
		
    	printf("\n\033[32m LOID : \033[0m");
        if(input == answer) {
            printf(
				"You're right!\n"
				"\033[1;31m ANYA : \033[0mAnya is doing great at math!\n\n"
			);
			score++;
    	}
    	else if(input == 464646) { //godmode because im not doing all that ^^
    		printf("cheater lmao\n\n");
    		score += 5;
		}
        else {
			printf(
				"Ah.... That's not correct Anya. The answer is actually %d\n"
				"\033[1;31m ANYA : \033[0mAwww....\n\n", answer
			);
		}
		printf("\033[1;30m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");
    	questionIndex++;
    }
    while(questionIndex <= totalQuestions);
    
    return score;
}