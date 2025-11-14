void display() {
    printf("Counting with Papa (Spy Edition)\n");
}


int getQuestionAmount(int LVL) {
	if(LVL == 1) 
		return 5;
	else 
		return 10;
}


//because the randomiser prefers to pick mostly 3 digits
int balanceRange(int RANGE) {
	return rng(RANGE % (int)pow(10, rng(3, 1)), 1);
}


void mathFinish(int SCORE, int QUESTIONS, int *AP, int *EXP) {
	printf(
		"\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n"
		" LOID : Looks like you got %d out of %d right\n\n", SCORE, QUESTIONS
	);
	int percent = SCORE / QUESTIONS * 100;
	if(percent < 60) {
		(*AP)--;
		printf(
			" [ +0 EXP ] [ -1 AP ]\n"
			" LOID : This.... is not good Anya....\n"
			" ANYA : Um! Anya promises to do better next time papa!\n"
		);
	}
	else if(percent < 80) {
		(*EXP)++;
		(*AP)--;
		printf(
			" [ +1 EXP ] [ -1 AP ]\n"
			" LOID : Well.... It's not bad\n"
			" ANYA : Yay-"
			" LOID : But it's not good either...."
			" ANYA : .... Anya promises to do better next time papa!\n"
		);
	}
	else if(percent < 100) {
		*EP += 2;
		(*AP)--;
		printf(
			" [ +2 EXP ] [ -1 AP ]\n"
			" LOID : Good job Anya! You did well!\n"
			" ANYA : .... Anya will keep up!\n"
		);
	}
	else {
		*EP += 3;
		if(rng(100, 0) < 50) { //ap consumption chance
			(*AP)--;
			printf(" [ +3 EXP ] [ +1 AP ]\n");
		}
		else {
			(*AP)++;
			printf(" [ +3 EXP ] [ -1 AP ]\n");
		}
		printf(
				" LOID : Well done Anya! You got everything correct!\n"
				" ANYA : Yahoo!\n"
			);
	}
}


int playMath(int LVL) {
    display();
    printf("Current level: %d\n", LVL);

	int score = 0;
    int totalQuestions = getQuestionAmount(LVL);
	int rangeAddSub, rangeMul;
    switch(LVL) {
        case 1:
            rangeAddSub = 999;
            break;
        case 2: 
            rangeAddSub = 9999;
            rangeMul = 20;
            break;
        case 3:
            rangeMul = 50;
            break;
    }

    int operationUnlocked= 2;
    if(LVL > 1) operationUnlocked = 3;
    
    printf(
		" LOID : Alright Anya, I'm going to ask you %d questions. Are you ready?\n"
		" ANYA : Yes! Anya will do her best!\n\n", totalQuestions
	);
    
    int questionCount = 1;
	do {
        int x, y, answer;
        int input;
        int operation = rng(operationUnlocked, 0);    
        
        printf(
			"\n------ Question %d ------\n"
			" LOID : ", questionCount
		);
        switch(operation) {   
            case 0: //addition
                x = balanceRange(rangeAddSub);
                y = balanceRange(rangeAddSub);
                answer = x + y;

                printf(mathQuestion(operation, rng(4, 0)), x, y);
                break;
            case 1: //subtraction
                x = balanceRange(rangeAddSub);
                y = rng(rng(rangeAddSub, 0), 1);
                answer = x - y;
                
                printf(mathQuestion(operation, rng(4, 0)), x, y);
                break;
            case 2: //multiplication
                x = rng(rangeMul, 1);
                y = rng(rangeMul, 1);
                answer = x * y;
                                
                printf(mathQuestion(operation, rng(4, 0)), x, y);
                break;
        }

        printf("\n ANYA >> ");
        
		while(scanf("%d", &input) != 1) {
    		returnInvalid(); 
			printf(" LOID : That doesn't seem right let's try again\n LOID : ");
			printf(mathQuestion(operation, rng(4, 0)), x, y);
    		printf("\n ANYA >> ");
		}
		
    	printf("\n LOID : ");
        if(input == answer) {
            printf(
				"You're right!\n"
				" ANYA : Anya is doing great at math!\n\n"
			);
			score++;
    	}
        else {
			printf(
				"Ah.... That's not correct Anya. The answer is actually %d\n"
				" ANYA : Awww....\n\n", answer
			);
		}
    	questionCount++;
    }
    while(questionCount <= totalQuestions);
    
    return score;
}