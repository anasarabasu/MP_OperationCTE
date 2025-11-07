///*----------------------------------------
//    @LEVEL 
//    @CHANCE
//    @RETURNS
//*/
//int BP(int LEVEL, int CHANCE, int BP, int *AP) {
//    if(BP < 5) {
//        if(LEVEL == 1) CHANCE *= 0;
//        //level == 2 is default chance val
//        if(LEVEL == 3) CHANCE += 25;
//        if(LEVEL == 4) CHANCE += 50;
//        
//        if(rng(100, 0) < CHANCE) {
//            *AP--;
//            printf("Whooo");
//            return 1;
//        }
//        else    
//            return 0;
//    }
//    else if (rng(100, 0) < 50) { //max BP bonus chance
//        *AP += 2;
//        return 0;
//    }
//}
//
//void bondingActivity(int ACTIVITY) {
//    switch(ACTIVITY) {
//        case 1:
//            *DAMIAN += BP(PE, 25, *DAMIAN, AP);
//            break;
//        case 2:
//            *BECKY += BP(0, 75, *BECKY, AP);
//            break;
//        case 3:
//            *HENDERSON += BP(MATH, 50, *HENDERSON, AP);
//            break;
//        case 4
//    }
//}
//
//
//void morning_BPSelection(
//    int *ACTIVITY, int *AP,
//    int MATH, int PE, 
//    int DAMIAN, int BECKY, int HENDERSON, int BOND, 
//    int VENUE,
//    int PH_1, int PH_2, int PH_3, int PH_4, int PH_5, int PH_6, int PH_7) {
//        printf(
//            "\t[0] View Stats\n"
//            "\t[1] Annoy Damian\t\t"
//            "\t[2] Play with Becky\t\t"
//            "\t[3] Talk to Mr. Henderson\t\t"
//            "\t[4] Go home\n\n"
//            "choose\n"
//        );
//
//        int input;
//        do {
//            printf(" >>> ");
//            if(scanf("%d", &input) != 1) 
//                returnInvalid(); //not a number
//            else {
//                if(input < 0 || input > 4) returnInvalid(); //is a number but out of range
//                else if(input < 4 && input != 0 && *AP == 0) lowAP();
//                else if(input == 0) viewStats(VENUE, MATH, PE, DAMIAN, BECKY, HENDERSON, BOND, PH_1, PH_2, PH_3, PH_4, PH_5, PH_6, PH_7);
//            }
//        }
//        while(input <= 0 || input > 4 || input < 4 && *AP == 0);
//
//        printf(" ANYA : Anya will.... %s\n", getActivity(input));
//
//        *ACTIVITY = input;
//}
//
//void afternoon_ActivitySelection() {}
//
//void schoolEvening() {}