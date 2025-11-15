void gainBP(int CHOICE, int LEVEL, int CHANCE, int *BP, int *AP) {
    int random = rng(100, 0);

    if(*BP < 5) {
        if(LEVEL == 1) CHANCE *= 0;
        if(LEVEL == 2) CHANCE += 0; //also for conditional bond requirement
        if(LEVEL == 3) CHANCE += 25;
        if(LEVEL == 4) CHANCE += 50;
        
        if(random < CHANCE) {
            printf(
                "\n >> Anya and %s grew a slighty more closer today!\n"
                " [ -1 AP ] [ +1 BP ]\n\n"
                "%s\n",
                getName(CHOICE), bondingTip(1, CHOICE)
            );
            (*BP)++;
        }
        else {
            printf(
                "\n >> Anya and %s spent time together, nothing much happened though....\n"
                " [ -1 AP ] [ -0 BP ]\n\n"
                "%s\n",
                getName(CHOICE), bondingTip(0, CHOICE)
            );
		}
        (*AP)--;

        if(*BP == 5) {//BP max reward
            printf(
                "\n >> Anya has reached the highest bond level with %s!\n"
                " [ +3 AP BONUS ]\n\n"
                "%s\n"
				" ANYA : Waku waku!\n",
                getName(CHOICE), maxBondMessage(CHOICE)
            );
            (*AP) += 3;
        }
    }
    else { //max BP bonus chance
        if (rng(100, 0) < 50) { 
            printf(
                "\n >> Bonding with %s made Anya a little more motivated for the day!\n"
                " [ +2 AP BONUS ] [ MAX BP ]\n",
                getName(CHOICE)
            );
            *AP += 2; 
        }
        else {
            printf(
                "\n >> Anya and %s spent time together, nothing much happened though\n"
                " [ -1 AP ] [ MAX BP ]\n",
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