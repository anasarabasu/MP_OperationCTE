void gainBP(int CHOICE, int LEVEL, int CHANCE, int *BP, int *AP) {
    int random = rng(100, 0);

    if(*BP < 5) {
        if(LEVEL == 1) CHANCE *= 0;
        if(LEVEL == 2) CHANCE += 0; //also for conditional bond requirement
        if(LEVEL == 3) CHANCE += 25;
        if(LEVEL == 4) CHANCE += 50;
        
        if(random < CHANCE) {
            printf(
                "\n [ -1 AP ] [ +1 BP ]\n"
                " >> Anya and %s grew a slighty more closer today!\n"
                "%s\n\n"
                " ANYA : Anya had a lot of fun today!\n", 
                getName(CHOICE), bondingTip(1, CHOICE)
            );
            (*BP)++;
        }
        else {
            printf(
                "\n [ -1 AP ] [ -0 BP ]\n"
                " >> Anya and %s spent time together, nothing much happened though....\n"
                "%s\n\n"
                " ANYA : Um.... Today was ok!\n",
                getName(CHOICE), bondingTip(0, CHOICE)
            );
		}
        (*AP)--;

        if(*BP == 5) {//BP max reward
            printf(
                "\n [ +3 AP ]\n"
                " >> Anya has reached the highest bond level with %s's!\n"
                "%s\n",
                getName(CHOICE), maxBondMessage(CHOICE)
            );
            (*AP) += 3;
        }
    }
    else { //max BP bonus chance
        if (rng(100, 0) < 50) { 
            printf(
                "\n [ MAX BP ] [ +2 AP ]\n"
                " >> Bonding with %s made Anya a little more motivated for the day!\n", 
                getName(CHOICE)
            );
            *AP += 2; 
        }
        else {
            printf(
                "\n [ MAX BP ] [ -1 AP ]\n"
                " >> Anya and %s spent time together, nothing much happened though\n",
                getName(CHOICE)
            );
            (*AP)--;
        }
    }
}

void bondingActivity( 
		int ACTIVITY, int *AP,
		int *DAMIAN, int PE,
		int *BECKY,
		int *HENDERSON, int MATH) {
    switch(ACTIVITY) {
        case 1:
            gainBP(1, PE, 25, DAMIAN, AP);
            break;
        case 2:
            gainBP(2, 2, 75, BECKY, AP);
            break;
        case 3:
            gainBP(3, MATH, 50, HENDERSON, AP);
            break;
    }
}