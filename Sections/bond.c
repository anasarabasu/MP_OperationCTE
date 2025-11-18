/* RETURN the bonding tip string based on the INDEX */
char *bondingTip(bool SUCCEED, int INDEX) {
    if(SUCCEED) 
        switch(INDEX) {
            case 1:
                return " DAMIAN: Hmph.... not bad. You actually managed to keep up. I suppose I can tolerate your efforts a little more.\n ANYA : Hehe! Take that, Sy-on-boy! Don't get too proud!";
            case 2:
                return " BECKY : Ahaha! That was so much fun! Let's do this again sometime!\n ANYA : Yosh! Let's play again next time!";
            case 3:
                return " HENDERSON : Excellent work! Your performance shows considerable refinement. Truly admirable.\n ANYA : Yahooo! That was fun, even if he said boring stuff....";
            case 4:
                return " BOND : Borf! *wags tail*\n YOR: Hmmm... Bond seems very pleased! Maybe miss Anya can try again later and keep this up!\n ANYA : Hehe! Bond likes me mama!";
            default: return 0;
        }
    else
        switch(INDEX) {
            case 1:
                return " DAMIAN : Hmph.... you might want to focus on improving your PE skills first. Do try to keep up.\n ANYA : Huuhh! Meanie! Does Sy-on boy wanna get punched again?";
            case 2:
                return " BECKY : Hehe! Sorry, I'm not quite up for it right now.... but let's try this again soon!\n ANYA : Okay.... Next time we'll make it super fun!";
            case 3:
                return " HENDERSON : My, perhaps honing your math skills would be a most prudent endeavor before progressing further.\n ANYA : I don't wanna go to school anymore....";
            case 4:
                return " BOND : Borf!\n YOR : Hmmm.... Bond doesn't seem to be in the mood today. Maybe miss Anya can try again next time?\n ANYA : Okay mama....";
            default: return 0;
        }
}


/* RETURN the max bond message string based on the INDEX */
char *maxBondMessage(int INDEX) {
    switch(INDEX) {
        case 1: 
            return " DAMIAN : DAMIAN: Hmph.... you're not completely hopeless, I suppose. I guess I can introduce you to Mouseney Land. You might enjoy it there....";
        case 2: 
            return " BECKY : Hey! I think you'll like it there at the West Berlint Aquarium! There's penguins!";
        case 3: 
            return " MR. HENDERSON : My, what such elegance you've displayed! Perhaps a visit to the Ostania Art Museum would provide a most suitable enrichment for your talents.";
        case 4: 
            return " BOND : Borf!\n LOID : Haha.... looks like Bond's ready for a little adventure at Dogland!";
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
    int random = rng(100, 0);
    
    if(*BP < 5) {
        if(LVL == 1) CHANCE *= 0;
        if(LVL == 2) CHANCE += 0; //just putting it here
        if(LVL == 3) CHANCE += 25;
        if(LVL == 4) CHANCE += 50;
        
        if(random < CHANCE) {
            printf(
                "\n >> Anya and %s grew a slighty more closer today!\n"
                " [ -1 AP ] [ +1 BP ]\n\n"
                "%s\n",
                getName(CHOICE), bondingTip(true, CHOICE)
            );
            (*BP)++;
        }
        else {
            printf(
                "\n >> Anya and %s spent time together, nothing much happened though....\n"
                " [ -1 AP ] [ -0 BP ]\n\n"
                "%s\n",
                getName(CHOICE), bondingTip(false, CHOICE)
            );
		}
        (*AP)--;

        //BP max reward
        if(*BP == 5) {
            printf(
                "\n >> Anya has reached the highest bond level with %s!\n"
                " [ +3 AP BONUS ] [ UNLOCKED OUTING LOCATION ]\n\n"
                "%s\n"
				" ANYA : Waku waku!\n",
                getName(CHOICE), maxBondMessage(CHOICE)
            );
            *AP += 3;
        }
    }
    //max BP bonus chance
    else { 
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