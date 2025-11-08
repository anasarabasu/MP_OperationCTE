/* the core of the program */
void gameLoop() {
    bool showIntro = true;

    int AP = 0;
    int mthLVL = 1, peLVL = 1;
    int BP_Damian = 0, BP_Becky = 0, BP_Henderson = 0, BP_Bond = 0;
    
    int venue;
    int activity;
    
    // int camRolls = 5;
    int PH_1 = 1, PH_2 = 1, PH_3 = 1, PH_4 = 3, PH_5 = 3, PH_6 = 3, PH_7 = 3;

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
                            printf("Where would Anya like to go?\n");
                            displayOutingSelection(BP_Damian, BP_Becky, BP_Henderson, BP_Bond);
                            printf("\n\n");
                            
                            venue = inputInt(
                                7,
                                0, 
                                AP,
                                venue,
                                mthLVL, peLVL,
                                BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                                PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                            );
                            printf(" ANYA : Anya decided she wants to go to the.... %s\n", getVenue(venue));
                            
                            if(AP <= 3) AP = 3;
                            break;
                    }
                    
                    
                    getchar();
                    wipeScreen();
                }
            }
            else { //reg schooldays
                switch(time) {
                    case 0:
                        printf("What should Anya do today?");
                        displayMorningSelection();
                        printf("\n\n");
                        
                        activity = inputInt(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                        );
                        printf(" ANYA : Anya will.... %s\n", getActivity(activity));
                        
                        bondingActivity(
                            activity, &AP,
                            &BP_Damian, peLVL,
                            &BP_Becky,
                            &BP_Henderson, mthLVL,
                            &BP_Bond
                        );

                        break;
                    case 1:
                        printf("What should Anya do today?");
                        displayMorningSelection();
                        printf("\n\n");
                        
                        activity = inputInt(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                        );
                        printf(" ANYA : Anya will.... %s\n", getActivity(activity));
                        
                        bondingActivity(
                            activity, &AP,
                            &BP_Damian, peLVL,
                            &BP_Becky,
                            &BP_Henderson, mthLVL,
                            &BP_Bond
                        );
                        // schoolAfternoon();
                        //minigame
                        break;
                    case 2:
                        printf("What should Anya do today?");
                        displayMorningSelection();
                        printf("\n\n");
                        
                        activity = inputInt(
                            4,
                            1,
                            AP,
                            venue,
                            mthLVL, peLVL,
                            BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
                            PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
                        );
                        printf(" ANYA : Anya will.... %s\n", getActivity(activity));
                        
                        bondingActivity(
                            activity, &AP,
                            &BP_Damian, peLVL,
                            &BP_Becky,
                            &BP_Henderson, mthLVL,
                            &BP_Bond
                        );
                        // schoolEvening();

                        AP++;
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