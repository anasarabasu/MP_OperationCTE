/* the core of the program */
void gameLoop() {
    bool showIntro = true;

    int AP = 0;
    int mthLVL = 1, peLVL = 1;
    int BP_Damian = 0, BP_Becky = 0, BP_Henderson = 0, BP_Bond = 0;
    
    int activity;

    int camRolls = 5;
    int currentVenue;
    int PH_1 = 1, PH_2 = 1, PH_3 = 1, PH_4 = 0, PH_5 = 0, PH_6 = 0, PH_7 = 0;

    
    int day = 0;
    while(day <= 40) {
        for(int time = 0; time != 3; time++) { //am nn pm iterator
            ui(day, time, AP);
            
            if(day%4 == 0) { //outing days
                if(showIntro == 1) {
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
                        case 2:
                        	displayVenues(BP_Damian, BP_Becky, BP_Henderson, BP_Bond);
                        	printf("\n\nWhere would Anya like to go?\n\n");
                            int input = inputInt(
                            	0, 
								7,
								0,
								mthLVL, peLVL,
								BP_Damian, BP_Becky, BP_Becky, BP_Bond,
								PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
							);
							printf("ANYA: Anya decided she wants to go to the.... %s\n", getVenue(input));
                            break;
                    }
                    getchar();
                    wipeScreen();
                }
            }
            else { //reg schooldays
                switch(time) {
                case 0:
//                    morning_BPSelection(
//                        &activity, &AP,
//                        mthLVL, peLVL, 
//                        BP_Damian, BP_Becky, BP_Henderson, BP_Bond,
//                        currentVenue,
//                        PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7
//                    );
//                    bondingActivity(activity);
                    break;
                case 1:
                    // schoolAfternoon();
                    //minigame
                    break;
                case 3:
                    // schoolEvening();
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