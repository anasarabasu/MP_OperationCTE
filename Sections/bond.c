/* RETURN the bonding tip string based on the INDEX */
char *bondingTip(bool SUCCEED, int INDEX, int LVL) {
    if(SUCCEED) 
        switch(INDEX) {
            case 1:
                return 
                    "\033[32m DAMIAN : \033[0m Hmph.... not bad. You actually managed to keep up\n"
                    "          I suppose I can tolerate your efforts a little more\n\n"
                    "\033[1;31mm ANYA : \033[0mHehe! Take that, Sy-on-boy! Don't get too proud!";
            case 2:
                return 
                    "\033[35m BECKY : \033[0mAhaha! That was so much fun! Let's do this again sometime!\n\n"
                    "\033[1;31m ANYA : \033[0mYosh! Let's play again next time!";
            case 3:
                return 
                    "\033[34m MR. HENDERSON : \033[0mExcellent work! Your performance shows considerable refinement\n"
                    "                 Truly admirable\n\n"
                    "\033[1;31m ANYA : \033[0mYahooo! That was fun, even if he said boring stuff....";
            case 4:
                return 
                    "\033[1;30m BOND : \033[0mBorf! *wags tail*\n\n"
                    "\033[31m YOR: \033[0mHmmm... Bond seems very pleased! Maybe miss Anya can try again later and keep this up!\n\n"
                    "\033[1;31m ANYA : \033[0m Hehe! Bond likes me mama!";
            default: return 0;
        }
    else
        switch(INDEX) {
            case 1:
                if(LVL == 4)
                    return
                        "\033[33m DAMIAN : \033[0mHmmmm.... today doesnt seem like the right time for this. Try again later\n"
                        "\033[1;30m          (Not really in the mood for this today....)\n\n"
                        "\033[1;31m ANYA : \033[0mHuuhh! Meanie! Does Sy-on boy wanna get punched again?";
                else return
                        "\033[33m DAMIAN : \033[0mHmm.... today doesnt seem like the right time for this. Try again later\n"
                        "\033[1;30m          (Hmph.... you might want to focus on improving your PE skills first)\n\n"
                        "\033[1;31m ANYA : \033[0m Huuhh! Meanie! Does Sy-on boy wanna get punched again?";
            case 2:
                return 
                    "\033[35m BECKY : \033[0mHehe! This was a bit fun!.... \n"
                    "         Let's try this again soon!\n"
                    "\033[1;30m         (I'm not really fealling it right now....)\n\n"
                    "\033[1;31m ANYA : \033[0m Okay.... Next time we'll make it super fun!";
            case 3:
                if(LVL == 4)
                    return  
                        "\033[34m MR. HENDERSON : \033[0mA most commendable effort, but there is room for improvement\n"
                        "                 You should strive to sharpen your skills before the next lesson\n"
                        "\033[1;30m                 (Not quite the right day for this… perhaps another attempt will be better)\n\n"
                        "\033[1;31m ANYA : \033[0m Anya doesn't don't wanna go to school anymore....";
                else return
                        "\033[34m MR. HENDERSON : \033[0mA most commendable effort, but there is room for improvement\n"
                        "                 You should strive to sharpen your skills before the next lesson\n"
                        "\033[1;30m                 (My, perhaps honing your math skills would be a most prudent endeavor before progressing further)\n\n"
                        "\033[1;31m ANYA : \033[0m Anya doesn't wanna go to school anymore....";
            default: return 0;
        }
}


/* RETURN the max bond message string based on the INDEX */
char *maxBondMessage(int INDEX) {
    switch(INDEX) {
        case 1: 
            return "\033[33m DAMIAN : \033[0mDAMIAN: Hmph.... you're not completely hopeless, I suppose\n        I guess I can introduce you to Mouseney Land. You might enjoy it there....";
        case 2: 
            return "\033[35m BECKY : \033[0mHey! I think you'll like it there at the West Berlint Aquarium! There's penguins!";
        case 3: 
            return "\033[34m\n\n MR. HENDERSON : \033[0mMy, what such elegance you've displayed!\n             Perhaps a visit to the Ostania Art Museum would provide a most suitable enrichment for your talents.";
        case 4: 
            return "\033[1;30m BOND : \033[0mBorf!\n\n\033[32m LOID : \033[0mHaha.... looks like Bond's ready for a little adventure at Dogland!";
        default: return 0;
    }
}


/* determines whether to increase BP & to reward the max BP bonus
    PRECONDITION 
        - must be non-negative values    
        - must be valid values
            [CHOICE 1 - 4]
            [LVL 1 - 4]

    @CHOICE - chosen bond partner
    @LVL - current skill level
    @CHANCE - initial chance value from the chosen bond partner
    @BP - pointer to the chosen BP 
    @AP - pointer to the current AP
*/
void gainBP(int CHOICE, int LVL, int CHANCE, int *BP, int *AP) {
    printf("\033[1;30m\n-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\033[0m\n");

    int random = rng(100, 0);
    
    if(*BP < 5) {
        if(LVL == 1) CHANCE *= 0;
        if(LVL == 2) CHANCE += 0; //just putting it here
        if(LVL == 3) CHANCE += 25;
        if(LVL == 4) CHANCE += 50;
        
        if(random < CHANCE) {
            printf(
                "\n >> Anya and %s grew a slighty more closer today!\n"
                "\033[31m [ -1 AP ]\033[32m [ +1 BP ]\n\n"
                "%s\n",
                getName(CHOICE), bondingTip(true, CHOICE, LVL)
            );
            (*BP)++;
        }
        else {
            printf(
                "\n >> Anya and %s spent time together, nothing much happened though....\n"
                "\033[31m [ -1 AP ]\033[1;30m [ -0 BP ]\n\n"
                "%s\n",
                getName(CHOICE), bondingTip(false, CHOICE, LVL)
            );
		}
        (*AP)--;

        //BP max reward
        if(*BP == 5) {
            printf(
                "\n >> Anya has reached the highest bond level with %s!\n"
                "\033[32m [ +3 AP BONUS ] [ UNLOCKED OUTING LOCATION ]\n\n"
                "%s\n"
				"\033[1;31m ANYA : \033[0mWaku waku!\n",
                getName(CHOICE), maxBondMessage(CHOICE)
            );
            *AP += 3;
        }
    }
    //max BP bonus chance
    else { 
        if (rng(100, 0) < 50) { 
            printf(
                "\033[1;30m\n >> Bonding with %s made Anya a little more motivated for the day!\n"
                "\033[32m [ +2 AP BONUS ] \033[1;30m[ MAX BP ]\n",
                getName(CHOICE)
            );
            *AP += 2; 
        }
        else {
            printf(
                "\033[1;30m\n >> Anya and %s spent time together, nothing much happened though\n"
                "\033[31m [ -1 AP ] \033[1;30m[ MAX BP ]\n",
                getName(CHOICE)
            );
            (*AP)--;
        }
    }
}


/* determines whether to make a change to the chosen bond parter's current relationship level
    PRECONDITION
        - must be non-negative values
        - ACTIVITY must be a valid value [1 - 3]

    @ACTIVITY - the current activity choses
    @AP - pointer to current AP

    -- pointer to the bond partner level --
        @DAMIAN
        @BECKY
        @HENDERSON

    @PE, MATH - current skill level
*/
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