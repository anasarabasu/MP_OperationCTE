/*  displays the title screen */
void title() {
    titleArt();
    wipeScreen();
}


/* the core of the program 
	@END pointer to the variable that will determine the ending
*/
void gameLoop(int *END) {
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
                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
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
								printf("Did you do well?");
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
	                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
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
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
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
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
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
    PH_1 = PH_1 % 4 == 0;
    PH_2 = PH_2 % 4 == 0;
    PH_3 = PH_3 % 4 == 0;
    PH_4 = PH_4 % 4 == 0;
    PH_5 = PH_5 % 4 == 0;
    PH_6 = PH_6 % 4 == 0;
    PH_2 = PH_7 % 4 == 0;
    
    if(PH_1 + PH_2 + PH_3 + PH_4 + PH_5 + PH_6 + PH_7 == 7) *END = 1;
    else if(PH_1 + PH_2 + PH_3 + PH_4 + PH_5 + PH_6 + PH_7 >= 3 && mthLVL == 4 && peLVL == 4) *END = 0;
    else *END = -1;
}