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


/* to "even it out" because the rng prefers to pick mostly 3 digits :( */
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
    printf("Counting with Papa (Spy Edition)\n");
    printf("Current level: %d\n", LVL);

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
    
    printf(
		" LOID : Alright Anya, I'm going to ask you %d questions. Are you ready?\n"
		" ANYA : Yes! Anya will do her best papa!\n\n", totalQuestions
	);
    
    int questionIndex = 1;
	do {
        int x, y, answer;
        int input;
        int operation = rng(operationUnlocked, 0);    
        
        printf(
			"\n------ Question #%d ------\n"
			" LOID : ", 
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

        printf("\n >> ");
        
		while(scanf("%d", &input) != 1) { //user input is not a number
    		returnInvalid(); 

			printf(" LOID : That doesn't seem right let's try again\n LOID : ");
			printf(mathQuestion(operation), x, y);
    		printf("\n >> ");
		}
		
    	printf("\n LOID : ");
        if(input == answer) {
            printf(
				"You're right!\n"
				" ANYA : Anya is doing great at math!\n\n"
			);
			score++;
    	}
    	else if(input == 464646) { //godmode because im not doing all that ^^
    		printf("cheater lmao\n");
    		score += 5;
		}
        else {
			printf(
				"Ah.... That's not correct Anya. The answer is actually %d\n"
				" ANYA : Awww....\n\n", answer
			);
		}
    	questionIndex++;
    }
    while(questionIndex <= totalQuestions);
    
    return score;
}