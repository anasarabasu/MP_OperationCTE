/*  displays the title screen */
void title() {
    titleArt();
    wipeScreen();
}


/* introduction scene of the game */
void introduction() { //henderson  talking about the exam and the project or something echeche
    //introArt();
    
    printf(
        "Mr. Henderson: blah blah blah do this do that ELEGANCE\n math math pe assessment\n\n"
    );

    wipeScreen();
}


/* the core of the program */
void gameLoop() {
    bool showIntro = true;

    int AP = 0;
    
    int activity;

    int BP_Damian = 0, BP_Becky = 0, BP_Henderson = 0, BP_Bond = 0;
    
    int mthLVL = 1, mthEXP = 0;
    int peLVL = 1, peEXP = 0;
    
    int venue;
    int PH_1 = 1, PH_2 = 1, PH_3 = 1, PH_4 = 0, PH_5 = 0, PH_6 = 0, PH_7 = 0;
    int PH_1_Key = generateVenueKey();
    int PH_2_Key = generateVenueKey();
    int PH_3_Key = generateVenueKey();
    int PH_4_Key = generateVenueKey();
    int PH_5_Key = generateVenueKey();
    int PH_6_Key = generateVenueKey();
    int PH_7_Key = generateVenueKey();

    int time = 0;
    int day = 0;
    while(day <= 40) {

        
        //am nn pm iterator
        for(time = 0; time != 3; time++) { 
            displayHeader(day, time);
            
            //outing days
            if(day % 4 == 0) { 
                if(showIntro) {
                    introduction(); //DO THIS AT THE LAST-ish WEEK
                    showIntro = false;
                    time++;
                }
                else {
                    switch(time) {
                        case 0: //morning segway
                            break;
                        case 1: //minigame
                            int *venueRating = getVenueRating(
                                venue,
                                &PH_1, &PH_2, &PH_3, &PH_4, &PH_5, &PH_6, &PH_7);

                            int venueKey = getVenueKey(
                                venue,
                                PH_1_Key, PH_2_Key, PH_3_Key, PH_4_Key, PH_5_Key, PH_6_Key, PH_7_Key);

                            *venueRating = startPhotoMini(venue, venueKey, &AP);

                            break;
                        case 2: //venue selection
                            printf(" ANYA : Hmmmm.... where should Anya go?\n");
                            displayOutingSelection(BP_Damian, BP_Becky, BP_Henderson, BP_Bond);
                            
                            venue = checkSelection(
                                7,
                                0, 
                                AP,
                                venue,
                                mthLVL, peLVL,
                                BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                            );
                            printf(" ANYA : Anya decided she wants to go to the.... %s!\n", getVenue(venue));

                            break;
                    }
                }
            }
            //reg schooldays
            else { 
                switch(time) {
                    case 0: //bonding activity
                        printf(" ANYA : Hmmmm.... What should Anya do?\n");
                        displayMorningSelection();
                        
                        activity = checkSelection(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                        );
                        printf(" ANYA : Anya will.... %s!\n", getActivity(activity));
                        
                        bondingActivity(
                            activity, &AP,
                            &BP_Damian, peLVL,
                            &BP_Becky,
                            &BP_Henderson, mthLVL
                        );
                        getchar(); //possible linux-specific bug?
						wipeScreen();

                        break;
                    case 1: //minigame (or bonding activity with the dog)
                        printf(" ANYA : Hmmmm.... What should Anya do?\n");
                        displayAfternoonSelection();
                        
                        activity = checkSelection(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                        );
                        printf(" ANYA : Anya will.... %s!\n", getActivity(activity+4));
                        
                        switch(activity) {
                            case 1: {

                                wipeScreen();
                                
                                int score = startMathMini(mthLVL);
                                finishMini(score, getTotal(mthLVL), &AP, &mthEXP, 0);
                                levelUp(&mthLVL, mthEXP);
                                
                                break;
                            }
                            case 2: {

                                wipeScreen();
                                
                                int score = startPEMini(peLVL);
                                finishMini(score, getTotal(peLVL), &AP, &peEXP, 1);
                                levelUp(&peLVL, peEXP);
                                
                                break;
                            }
                            case 3:
                                gainBP(4, 2, 100, &BP_Bond, &AP);
                                break;
                    	}
                        //compute exp
                        time++;

                        break;
                }
            }
        }
		endDay(day, &AP);
        day++;
    }
}


/* decidees which ending to display
    PRECONDITION : must not be garbage values

    @PHOTO_TOTAL - summary of the photo mini results
    @SKILLS_TOTAL - summary of the math & pe levels
*/
void theEnd() {
    //-1

    //0

    //1
    /*
    Perfect Ending: Anya succeeds in submitting her project and ends up with near-top ranks in the exams. As a result, she is awarded the Stella Star, with Mr. Henderson praising her for her performance being “Very Elegant”. This ending is achievable by obtaining a PERFECT rating in ALL memorable photos for ALL venues. 

    Neutral Ending: Anya submits her project, but there are better projects that have been submitted. However, she passes her exams, but does not earn the Stella Star. This ending is achieved by obtaining a PERFECT memorable photo rating in at least 3 venues and maxing out her Math and PE levels 

    Bad Ending: Anya submits her project, but it is incomplete. Likewise, she does not pass her exams and, to Loid’s dismay, Anya gets a Tonitrus bolt for her performance. This ending is obtained if less than 3 PERFECT memorable photo ratings are obtained or her PE and MATH levels are not maxed out Page  
    */


}

