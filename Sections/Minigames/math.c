void display() {
    printf("Counting with Papa (Spy Edition)");
}


void playMath(int LVL) {
    display();
    printf("Current level: %d", LVL);

    int totalQuestions, rangeAddSuh, rangeMul;
    switch(LVL) {
        case 1:
            totalQuestions = 5;
            rangeAddSuh = 999;
            break;
        case 2: 
            totalQuestions = 10;
            rangeAddSuh = 9999;
            rangeMul = 20;
            break;
        case 3:
            rangeMul = 50;
            break;
    }

    for(int question = 0;question != 50; question++) {
        int x, y, answer;
        int input;

        switch(rng(2, 0)) {
            case 0: //addition
                x = rng(rangeAddSuh, 1);
                y = rng(rangeAddSuh, 1);
                answer = x + y;

                printf("What is %d + %d?\n\n", x, y);
                break;
            case 1: //subtraction
                x = rng(rangeAddSuh, 1);
                y = rng(rangeAddSuh, 1);
                answer = x - y;
                
                printf("What is %d - %d?\n\n", x, y);
                break;
            case 2: //multiplication
                x = rng(rangeMul, 1);
                y = rng(rangeMul, 1);
                answer = x * y;
                printf("What is %d x %d?\n\n", x, y);
                break;
        }

        printf(" >> ");
        scanf("%d", &input);

        if(input == answer)
            printf("whopee");
        else printf("f");
    }
}