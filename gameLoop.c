/* the core of the program */
void gameLoop() {
    bool showIntro = true;

    int venue;
    int activity;
    
    int AP = 0;

    int BP_Damian = 0, BP_Becky = 0, BP_Henderson = 0, BP_Bond = 0;
    
    int mthLVL = 1, peLVL = 1;
     int mthEXP = 0, peEXP = 0;
    
    // int camRolls = 5;
    int PH_1 = 1, PH_2 = 1, PH_3 = 1, PH_4 = 0, PH_5 = 0, PH_6 = 0, PH_7 = 0;

    int time = 0;
    int day = 0;
    while(day <= 40) {

        
        for(time = 0; time != 3; time++) { //am nn pm iterator
            ui(day, time);
            
            if(day%4 == 0) { //outing days
                if(showIntro) {
                    introduction(); //DO THIS AT THE LAST-ish WEEK
                    showIntro = false;
                    time++;
                }
                else {
                    switch(time) {
                        case 0:
                        // outingMorning(currentVenue);
                            break;
                        case 1:
                        // outingAfternoon(currentVenue);
                        //minigame
                            break;
                        case 2: //evening - outing selection
                            printf(" ANYA : Hmmmm.... where should Anya go?\n");
                            displayOutingSelection(BP_Damian, BP_Becky, BP_Henderson, BP_Bond);
                            
                            venue = inputInt(
                                7,
                                0, 
                                AP,
                                venue,
                                mthLVL, peLVL,
                                BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                            );
                            printf(" ANYA : Anya decided she wants to go to the.... %s!\n", getVenue(venue));
                            
                            if(AP <= 3) AP = 3;
                            break;
                    }
                    
                    
                    getchar();
                    wipeScreen();
                }
            }
            else { //reg schooldays
                switch(time) {
                    case 0: //morning - bonding activity
                        printf(" ANYA : Hmmmm.... What should Anya do?\n");
                        displayMorningSelection();
                        
                        activity = inputInt(
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

                        break;
                    case 1: //afternoon - minigame / bond
                        printf(" ANYA : Hmmmm.... What should Anya do?\n");
                        displayAfternoonSelection();
                        
                        activity = inputInt(
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
                            case 1:
                                getchar();
                                wipeScreen();

                                int score = playMath(mthLVL);
                                mathFinish(score, getQuestionAmount(mthLVL), &AP, &mthEXP);
                                break;
                            case 2:
                                getchar();
                                wipeScreen();
                                
                                break;
                            case 3:
                                gainBP(4, 2, 100, &BP_Bond, &AP);
                                break;
                        }

                        //compute exp
                        time++
                        ;
                        break;
                }
                getchar();
                wipeScreen();
            }
            // system("clear");
        }
        day++;
    }
}