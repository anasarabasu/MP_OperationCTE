void displayOutingSelection(int DAMIAN, int BECKY, int HENDERSON, int BOND) {
    printf(
        "\t[0] View Stats\n"
        "\t[1] Park\t\t\t"
        "\t[2] City Mall\t\t\t"
        "\t[3] Ostania Beach\n"
    );
    
    printf("\t%s", (BECKY == 5) ? "[4] West Berlint Aquarium\t" : "[X] LOCKED\t\t\t");
    printf("\t%s", (HENDERSON == 5) ? "[5] Ostania Art Museum\t\t" : "[X] LOCKED\t\t\t");
    printf("\t%s", (DAMIAN == 5) ? "[6] Berlint Mouseney Land\t\t" : "[X] LOCKED\t\t\t");
    printf("\t%s", (BOND == 5) ? "[7] Park Avenue Dogland\t\t" : "[X] LOCKED\t\t\t");

    printf("\n\n");
}


void displayMorningSelection() {
	printf(
	    "\t[0] View Stats\n"
	    "\t[1] Annoy Damian\t\t"
	    "\t[2] Play with Becky\t\t"
	    "\t[3] Talk to Mr. Henderson\t\t"
	    "\t[4] Go home\n\n"
	);	
}


void displayAfternoonSelection() {
    printf(
	    "\t[0] View Stats\n"
        "\t[1] Study with Loid\t\t"
        "\t[2] Train with Yor\t\t"
        "\t[3] Play with Bond\t\t"
        "\t[4] Slack off\n\n"
    );
}