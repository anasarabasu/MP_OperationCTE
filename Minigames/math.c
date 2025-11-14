void display() {
    printf("Counting with Papa (Spy Edition)\n");
}


//because the randomiser prefers to pick mostly 3 digits
int balanceRange(int RANGE) {
	return rng(RANGE % (int)pow(10, rng(3, 1)), 1);
}


void playMath(int LVL) {
    display();
    printf("Current level: %d\n", LVL);

    int totalQuestions, rangeAddSub, rangeMul;
    switch(LVL) {
        case 1:
            totalQuestions = 5;
            rangeAddSub = 999;
            break;
        case 2: 
            totalQuestions = 10;
            rangeAddSub = 9999;
            rangeMul = 20;
            break;
        case 3:
            rangeMul = 50;
            break;
    }

    int operations = 2;
    if(LVL > 1) operations = 3;
    
    printf(
		" LOID : Alright Anya, I'm going to ask you %d questions. Are you ready?\n"
		" ANYA : Yes! Anya will do her best!\n\n", totalQuestions
	);
    
    for(int q = 1; q <= totalQuestions; q++) {
        int x, y, answer;
        int input;
        
        printf(" LOID : ", q);

        switch(rng(operations, 0)) {   
            case 0: //addition
                x = balanceRange(rangeAddSub);
                y = balanceRange(rangeAddSub);
                answer = x + y;

                printf(mathQuestion(0, rng(4, 0)), x, y);
                break;
            case 1: //subtraction
                x = balanceRange(rangeAddSub);
                y = rng(rng(rangeAddSub, 0), 1);
                answer = x - y;
                
                printf(mathQuestion(1, rng(4, 0)), x, y);
                break;
            case 2: //multiplication
                x = rng(rangeMul, 1);
                y = rng(rangeMul, 1);
                answer = x * y;
                                
                printf(mathQuestion(2, rng(4, 0)), x, y);
                break;
        }

        printf("\n ANYA >> ");
        scanf("%d", &input);

		printf("\n LOID : ");
        if(input == answer) {
            printf(
				"You're right!\n"
				" ANYA : Anya is doing great at math!\n\n"
			);
    	}
        else {
			printf(
				"Ah.... That's not correct Anya. The answer is actually %d\n"
				" ANYA : Awww....\n\n", answer
			);
		}
        
    }
}