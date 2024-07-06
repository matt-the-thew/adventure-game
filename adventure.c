#include <stdio.h>
#include <unistd.h>
#include <stdbool.h>
#include <string.h>

bool have_torch = false;

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

int main(void) {
	
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
	
	what_do_you_do();

	bool escaped_cell = false;
	bool looked = false;
	bool searched_corpse = false;
	bool unlocked_door = false;
	bool spoke_to_man = false;

	char look[] = "LOOK";
	char try_door[] = "TRY DOOR";
	char speak[] = "SPEAK";
	char search_corpse[] = "SEARCH CORPSE";
	char unlock_door[] = "UNLOCK DOOR";
	char take_torch[] = "TAKE TORCH";
	char leave_cell[] = "LEAVE CELL";
	char action[20];
	
	while (!escaped_cell) {
		printf("\n");
		printf("YOU CAN...\n");
		if (!looked) {printf("LOOK\n");}
		if (looked && !searched_corpse) {printf("SEARCH CORPSE\n");}
		if (looked && !have_torch) {printf("TAKE TORCH\n");}
		if (!searched_corpse && !unlocked_door) {printf("TRY DOOR\n");}
		if (searched_corpse && !unlocked_door) {printf("UNLOCK DOOR\n");}
		if (unlocked_door) {printf("LEAVE CELL\n");}
		if (!spoke_to_man) {printf("SPEAK\n");}
		what_do_you_do();
		printf("\n");
		
		scanf("%19[^\n]s", &action[0]);

		if (compare_characters(action, look) == 1) {
			printf("There is a CHAIR in a corner of the room.\n");
			printf("There is a UNLIT TORCH in a bracket on the wall\n");
			print_medium_pause("There is a ROTTING CORPSE slumped on the floor.");

			looked = true;
		}

		if (compare_characters(action, take_torch) == 1 && looked == true) {
			printf("YOU SEIZE THE TORCH FROM ITS BRACKET.\n");
			printf("IT HAS BEEN USED IN THE PAST.\n");
			printf("MAYBE THEY USED TO LET THE PRISONERS SEE.\n");
			printf("HOW KIND.\n");

			have_torch = true;
		}

		if (compare_characters(action, try_door) == 1 && searched_corpse == false) {
			printf("HE WASN'T LYING. IT WON'T BUDGE\n");
			printf("THERE IS A GAP BETWEEN THE DOOR AND THE STONE WALL.\n");
			print_medium_pause("IT SEEMS TO BE LOCKED WITH A BAR FROM THE OUTSIDE.");
		}

		if (compare_characters(action, speak) == 1) {
			print_long_pause("YOU ASK THE OLD MAN WHO HE IS.");
			print_medium_pause("No one important. Just an old criminal. Like you!");
			print_medium_pause("heh heh ...");
			print_medium_pause("...");
			print_long_pause("YOU ASK THE OLD MAN WHERE YOU ARE.");
			print_medium_pause("Those guards really laid into you.");
			print_medium_pause("We're under the castle. This is the King's dungeon.");
			print_medium_pause("The NEW King, at least.");
			print_medium_pause("YOU DO NOT REMEMBER MUCH. THIS TROUBLES YOU.");

			spoke_to_man = true;
		}

		if (compare_characters(action, search_corpse) == 1 && looked == true) {
			printf("YOU RIFLE THROUGH THE CORPSE'S POCKETS.\n");
			printf("THERE IS A PIECE OF WIRE SEWN INTO THE LINING OF THE JACKET.\n");
			print_medium_pause("HE WAS A THIEF. A LOCKPICK, MAYBE. THE GUARDS MISSED THIS.");

			searched_corpse = true;
		}

		if (compare_characters(action, unlock_door) == 1 && searched_corpse == true) {
			printf("THE WIRE WORKS PERFECTLY FOR THIS.\n");
			printf("SURELY THE THIEF WAS PLANNING TO DO THE SAME.\n");
			print_medium_pause("THE DOOR SWINGS WIDE. THE OLD MAN PIPES UP.");
			print_long_pause("Damn. Nice going, stranger.");
			print_long_pause("Maybe we'll get out of here yet.");

			unlocked_door = true;
		}

		if (compare_characters(action, leave_cell) == 1) {
			print_medium_pause("THE DOOR SWINGS WIDE.");
			print_medium_pause("THERE IS ONLY DARKNESS WITHOUT.");
			print_long_pause("IT WRAPS ICY HANDS AROUND YOU AS YOU STEP FORWARD.");

			escaped_cell = true;
		}

		strcpy(action, "");
		fflush(stdin);
	}

printf("FIRST ROOM COMPLETED!");

	bool snuck_out_of_dungeon = false;
	bool knocked_out_guard = false;
	char current_location[15] = "CELL_DOOR";




	while (!snuck_out_of_dungeon) {
		if (strcmp(current_location, "CELL_DOOR") == 0) {
			printf("THE CORRIDOR STRETCHES IN OPPOSITE DIRECTIONS.\n");
			if (!knocked_out_guard) {printf("THERE ARE FOOTSTEPS TO THE RIGHT.\n");}
			printf("THE WALLS ARE OF DANK STONE, WELL CUT.\n");
			printf("YOU CAN...\n");
			printf("GO LEFT\n");
			printf("GO RIGHT\n");
			what_do_you_do();
		}

		if (strcmp(current_location, "GUARD_ROOM") == 0) {
			printf("LIGHT CREEPS TOWARDS YOU AS YOU WALK.\n");
			printf("THERE IS A SMALL GARRISON OF GUARDS HERE.\n");
			if(!knocked_out_guard) {
				printf("ONLY ONE IS ON PATROL.\n");
				printf("HE WALKS WEARILY FROM ONE SIDE OF THE ROOM TO THE OTHER.\n");
				printf("HIS EYES ARE DULL.\n");
			}
			printf("YOU CAN...\n");
			printf("LOOK\n");
			if (!knocked_out_guard)
			what_do_you_do();
		}

		scanf("%19[^\n]s", &action[0]);

		if (compare_characters(action, "GO LEFT") == 1) {
			strcpy(current_location, "GUARD_ROOM");
		}

	strcpy(action, "");
	fflush(stdin);
	}

	return 0;
}