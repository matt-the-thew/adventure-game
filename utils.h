#ifndef UTILS_H
#define UTILS_H
#include <stdio.h>
#include <unistd.h>

void print_medium_pause(char *text) {
	printf("%s", text);
	printf("\n");
	sleep(2);
}

void print_long_pause(char *text) {
	printf("%s", text);
	printf("\n");
	sleep(5);
}

void what_do_you_do(void) {
	printf("WHAT DO YOU DO?\n");
}

int compare_characters(char string1[50], char string2[50]) {
    if (strlen(string1) != strlen(string2)) {
        return 0;
    }
	for (int i = 0; i < strlen(string1); i++) {
        if (string1[i] != string2[i]) {
            return 0;
        }
    }
    return 1;
}

void print_intro_cell_interior(void) {
    print_medium_pause("\"Greetings, adventurer.\"");
	print_medium_pause("\"...\"");
	print_medium_pause("\"Wasn't sure you'd make it back to me.\"");
	print_medium_pause("\"Alright then. On your feet.\"");
	sleep(3);

	print_long_pause("THERE IS A STOOPED MAN IN FRONT OF YOU. HIS LONG WHITE BEARD FLASHES IN THE DIM LIGHT.");
	print_long_pause("IT SMELLS LIKE MOLD IN HERE. UNFORGIVING STONE BENEATH YOUR FEET AND ABOVE YOUR HEAD.");
	print_long_pause("HE SEES YOUR EYES SETTLE ON THE IRON DOOR.");

	print_medium_pause("\"Don't bother.\"");
	print_medium_pause("\"Damn thing won't budge.\"");
}
#endif