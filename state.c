/*  displays the title screen */
void title() {
    titleArt();
    wipeScreen();
}


/* A bit of fluff before the end */
void momentOfTruth(int ENDING) {
    char input[99];
    printf(
        "\n   Project submission & Assessment exam\n"
        "\033[31m   Morning\n"
        "\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n" 
        "\033[33m\t\t\t\t\t\t\t\t\t\t\tE  D  E  N    A  C  A  D  E  M  Y\n"
		"\033[0m-----------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------\n\n"
		"\033[34m MR. HENDERSON : \033[0mStudents.... it is time\n"
        "                 Please \033[33mSUBMIT\033[0m\ your collage with elegance\n\n"
        "\033[30m [ TYPE SUBMIT ] \033[0m>> "
    );

    bool check = false;

    do {
        scanf("%s", &input);
        if(strcasecmp(input, "submit") == 0) {
            check = true;   
            printf(
                "\n\033[1;31m ANYA : \033[0mH-here Mr. Henderson!\n"
                "        \033[0m(Anya feels.... %s)\n\n", 
                getEndingThoughts(ENDING, 0)
            );
        }
        else 
            printf(
                "\n\033[34m MR. HENDERSON : \033[0mAnya, please submit your work\n\n"
                "\033[1;31m ANYA : \033[0mOh-oh! Sorry!\n"
                " >> "
            );
    }
    while(!check);
    check = false;

    printf(
        "\033[34m MR. HENDERSON : \033[0m%s\n\n"
        "\033[1;31m ANYA : \033[0m(Huh? W-what does he mean by that....?)\n", getEndingThoughts(ENDING, 3)
    );

    awaitInput();

    printf(
		"\n\033[34m MR. HENDERSON : \033[0mIt is now time to \033[33mBEGIN\033[0m the assessments\n                 I expect each of you to focus and perform to the best of your abilities\n\n"
        " >> "
    );

    do {
    scanf("%s", &input);
    if(strcasecmp(input, "begin") == 0) {
        check = true;   
        printf(
            "\n\033[1;31m ANYA : \033[0mO-kay.... Anya can do this!\n"
            "        \033[0m(Anya feels.... %s)\n", 
            getEndingThoughts(ENDING, 0)
        );
    }
    else 
        printf(
            "\n\033[35m BECKY : \033[0mC'mon on Anya! You've got this!\n\n"
            "\033[33m DAMIAN : \033[0mHmph… don't mess it up, Anya.\n\n"
            "\033[1;31m ANYA : \033[0mOh-oh! Sorry!\n"
            " >> "
        );
    }
    while(!check);
    check = false;

    awaitInput();
    printf(
            "\n\033[1;31m ANYA : \033[0mHah! Everything's finally over!\n"
            "        Maybe.... maybe Anya can get a Stella....?\n\n"
            "\n\033[35m BECKY : \033[0mSee you tomorow! Byeeee!\n\n"
            "\033[33m DAMIAN : \033[0mHmph… don't get too excited, Anya. The Stella isn't guaranteed\n\n"
            "\033[1;31m ANYA : \033[0m....\n\n"
            "\033[34m MR. HENDERSON : \033[0mVery well, students. Head home safely\n"
            "                 The Stella results will be announced soon. Let's see who truly earns it\n"
    );
}


/* the end */
void theEnd(int ENDING) {
	momentOfTruth(ENDING);
    endDay(40, 0);

    theDayTM(ENDING);
    wipeScreen();

    displayEnding(ENDING);
}


/* the core of the program 
	@END pointer to the variable that will determine the ending
*/
void gameLoop() {
    bool showIntro = true;

    int AP = 0;
    
    int activity;

    int BP_Damian = 0, BP_Becky = 0, BP_Henderson = 0, BP_Bond = 0;
    
    int mthLVL = 1, mthEXP = 0;
    int peLVL = 1, peEXP = 0;
    
    int venue;
    
    int PH_1 = 0, PH_2 = 0, PH_3 = 0, PH_4 = 0, PH_5 = 0, PH_6 = 0, PH_7 = 0;
    int PH_1_Mem = 0, PH_2_Mem = 0, PH_3_Mem = 0, PH_4_Mem = 0, PH_5_Mem = 0, PH_6_Mem = 0, PH_7_Mem = 0;
    
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
        	if(day % 4 != 0 || ( day % 4 == 0 && time != 1)) displayHeader(day, time);
            
            //outing days
            if(day % 4 == 0) { 
                if(showIntro) {
                    introduction();
                    showIntro = false;
                    time++;
                }
                else {
                    switch(time) {
                        case 0: { //morning segway
                        	displayOutingMorningSelection();
                        	
                        	int action = checkSelection(
                        		2,
                        		1,
                        		AP,
                        		venue,
                                mthLVL, peLVL,
                                BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7,
                                &day
							);
							printf("\033[1;31m ANYA : \033[0mAnya will.... %s\n", getActivity(action + 8));
							
							if(action == 2) time++;
                        	
                        	wipeScreen();
                        	
                            break;
						}
                        case 1: { //minigame
                            int venueKey = getVenueKey(
                                venue,
                                PH_1_Key, PH_2_Key, PH_3_Key, PH_4_Key, PH_5_Key, PH_6_Key, PH_7_Key);

							int *venueMem = getVenueMem(
								venue,
								&PH_1_Mem, &PH_2_Mem, &PH_3_Mem, &PH_4_Mem, &PH_5_Mem, &PH_6_Mem, &PH_7_Mem);

                            int *venueRating = getVenueRating(
                                venue,
                                &PH_1, &PH_2, &PH_3, &PH_4, &PH_5, &PH_6, &PH_7);
                            *venueRating = startPhotoMini(venue, venueKey, venueMem, &AP);
							
							wipeScreen();
                        	
                            break;
						}
                        case 2: { //venue selection
                        	if(day == 40) { //skip this because its already the last day lol
                                dayBefore();
								day++; 
							}
							else {
	                            displayOutingVenueSelection(BP_Damian, BP_Becky, BP_Henderson, BP_Bond);
	                            
	                            venue = checkSelection(
	                                7,
	                                0, 
	                                AP,
	                                venue,
	                                mthLVL, peLVL,
	                                BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
	                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7,
                                    &day
	                            );
	                            printf("\033[1;31m ANYA : \033[0mAnya decided she wants to go to the.... %s!\n", getVenue(venue));
							}
                            //possible linux-specific bug? YES WTF
                            #if !defined(_WIN32) || !defined(_WIN64)
                                getchar();
                            #endif
                            break;
                    	}
                    }
                }
            }
            //reg schooldays
            else { 
                switch(time) {
                    case 0: { //bonding activity 
                        displayMorningSelection();
                        
                        activity = checkSelection(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7,
                            &day
                        );
                        printf("\033[1;31m ANYA : \033[0mAnya will.... %s!\n", getActivity(activity));
                        
                        bondingActivity(
                            activity, &AP,
                            &BP_Damian, peLVL,
                            &BP_Becky,
                            &BP_Henderson, mthLVL
                        );

                        //possible linux-specific bug? YES WTF
                        #if !defined(_WIN32) || !defined(_WIN64)
	                        getchar();
                        #endif
						
						wipeScreen();
                        break;
                	}
                    case 1: { //minigame (or bonding activity with the dog)
                        displayAfternoonSelection();
                        
                        activity = checkSelection(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7,
                            &day
                        );
                        printf(
							"\033[1;31m ANYA : \033[0m Anya will.... %s!\n",
							getActivity(activity+4)
						);

                        //possible linux-specific bug? YES WTF
                        #if !defined(_WIN32) || !defined(_WIN64)
	                        getchar();
                        #endif
							
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
                            case 3: {
                                gainBP(4, 2, 100, &BP_Bond, &AP);
                                break;
							}
							
                    	}
                        time++;
                        break;
                    }
                }
            }
        }
		endDay(day, &AP);
        day++;
    }
    
    // ENDING CHECK
    int venueTotal = ((PH_1 + 1) % 5 == 0) + ((PH_2 + 1) % 5 == 0) + ((PH_3 + 1) % 5 == 0) + ((PH_4 + 1) % 5 == 0) + ((PH_5 + 1) % 5 == 0) + ((PH_6 + 1) % 5 == 0) + ((PH_7 + 1) % 5 == 0);
    int skillTotal = mthLVL == 4 && peLVL == 4;

    int END;
    if(venueTotal == 7 && skillTotal) END = 1;
    else if(venueTotal >= 3 && skillTotal) END = 2;
    else END = 3;

    theEnd(END);

    viewStats(
        AP,
        venue,
        mthLVL, peLVL,
        BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
        PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
    );

    getchar();
}