#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include "utils.h"

char current_location[15] = "DUNGEON_CELL";


int main(void) {
//~~~~~~~~~~~~ROOM ONE: CELL INTERIOR~~~~~~~~~~~~~~~~~~~~~~
	bool have_torch = false;
	bool looked = false;
	bool searched_corpse = false;
	bool unlocked_door = false;
	bool spoke_to_man = false;

	char look[] = "look";
	char try_door[] = "try door";
	char speak[] = "speak";
	char search_corpse[] = "search corpse";
	char unlock_door[] = "unlock door";
	char take_torch[] = "take torch";
	char leave_cell[] = "leave cell";
	char action[20];

	// print_intro_cell_interior();

	while (strcmp(current_location, "DUNGEON_CELL") == 0) {
		printf("\n");
		printf("YOU CAN...\n");
		if (!looked) {printf("look\n");}
		if (looked && !searched_corpse) {printf("search corpse\n");}
		if (looked && !have_torch) {printf("take torch\n");}
		if (!searched_corpse && !unlocked_door) {printf("try door\n");}
		if (searched_corpse && !unlocked_door) {printf("unlock door\n");}
		if (unlocked_door) {printf("leave cell\n");}
		if (!spoke_to_man) {printf("speak\n");}
		what_do_you_do();
		printf("\n");
		
		scanf("%19[^\n]s", &action[0]);
		
		if (compare_characters(action, look) == true) {
			printf("There is a CHAIR in a corner of the room.\n");
			printf("There is a UNLIT TORCH in a bracket on the wall\n");
			print_medium_pause("There is a ROTTING CORPSE slumped on the floor.");

			looked = true;
		}

		if (compare_characters(action, take_torch) == true && looked == true) {
			printf("YOU SEIZE THE TORCH FROM ITS BRACKET.\n");
			printf("IT HAS BEEN USED IN THE PAST.\n");
			printf("MAYBE THEY USED TO LET THE PRISONERS SEE.\n");
			printf("HOW KIND.\n");

			have_torch = true;
		}

		if (compare_characters(action, try_door) == true && searched_corpse == false) {
			printf("HE WASN'T LYING. IT WON'T BUDGE\n");
			printf("THERE IS A GAP BETWEEN THE DOOR AND THE STONE WALL.\n");
			print_medium_pause("IT SEEMS TO BE LOCKED WITH A BAR FROM THE OUTSIDE.");
		}

		if (compare_characters(action, speak) == true) {
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

		if (compare_characters(action, search_corpse) == true && looked == true) {
			printf("YOU RIFLE THROUGH THE CORPSE'S POCKETS.\n");
			printf("THERE IS A PIECE OF WIRE SEWN INTO THE LINING OF THE JACKET.\n");
			print_medium_pause("HE WAS A THIEF. A LOCKPICK, MAYBE. THE GUARDS MISSED THIS.");

			searched_corpse = true;
		}

		if (compare_characters(action, unlock_door) == true && searched_corpse == true) {
			printf("THE WIRE WORKS PERFECTLY FOR THIS.\n");
			printf("SURELY THE THIEF WAS PLANNING TO DO THE SAME.\n");
			print_medium_pause("THE DOOR SWINGS WIDE. THE OLD MAN PIPES UP.");
			print_long_pause("Damn. Nice going, stranger.");
			print_long_pause("Maybe we'll get out of here yet.");

			unlocked_door = true;
		}

		if (compare_characters(action, leave_cell) == true) {
			print_medium_pause("THE DOOR SWINGS WIDE.");
			print_medium_pause("THERE IS ONLY DARKNESS WITHOUT.");
			print_long_pause("IT WRAPS ICY HANDS AROUND YOU AS YOU STEP FORWARD.");

			strcpy(current_location, "CELL_EXTERIOR");
		}

		strcpy(action, "");
		fflush(stdin);
	}

	printf("\n");
//~~~~~~~~~~~~~~~~~ROOM TWO: CELL EXTERIOR~~~~~~~~~~~~~~~
	bool knocked_out_guard = false;
	
	while (strcmp(current_location, "CELL_EXTERIOR") == 0) {
		printf("THE CORRIDOR STRETCHES IN OPPOSITE DIRECTIONS.\n");
		if (!knocked_out_guard) {printf("THERE ARE FOOTSTEPS TO THE RIGHT.\n");}
		printf("THE WALLS ARE OF DANK STONE, WELL CUT.\n");
		print_long_pause("SOMETHING EVIL IS TO THE RIGHT. IT WHISPERS TO YOU.\n");
		printf("YOU CAN...\n");
		printf("go left\n");
		printf("go right\n");
		what_do_you_do();

		scanf("%19[^\n]s", &action[0]);

		if (compare_characters(action, "go left") == true) {
			print_long_pause("LIGHT CREEPS TOWARDS YOU AS YOU WALK.");
			print_medium_pause("TORCH LIGHT.");
			strcpy(current_location, "GUARD_ROOM");

			fflush(stdin);
			strcpy(action, "");
		}

		if (compare_characters(action, "go right") == true) {
			print_long_pause("WHY WOULD YOU DO THIS?\n");
			print_medium_pause("\"This is unwise, adventurer.\"");
			print_medium_pause("\"I'm staying here.\"");
			print_medium_pause("THE STONE CORRIDOR TURNS TO UNEVEN STAIRS.");
			print_medium_pause("YOU STEP DEEPER INTO THE DUNGEON\'S BELLY.\n");
			print_medium_pause("THERE IS A CAVERN HERE.");
			print_medium_pause("A SINGLE BRAIZER BURNS WEAKLY UP AHEAD.");
			print_medium_pause("IT DOESN\'T GIVE ENOUGH LIGHT TO SEE THE WALLS.");
			print_long_pause("THERE IS SOMETHING VERY OLD HERE.");
			print_long_pause("YOU SHOULD GO, AND QUICKLY.");
			strcpy(current_location, "HEART_LAIR");

			fflush(stdin);
			strcpy(action, "");
		}

		fflush(stdin);
		strcpy(action, "");
	}

//~~~~~~~~~~~~~~~~ROOM THREE: GUARD ROOM~~~~~~~~~~~~~~~~
	while (strcmp(current_location, "GUARD_ROOM") == 0) {
		printf("THERE IS A SMALL GARRISON OF GUARDS HERE.\n");
		if(!knocked_out_guard) {
			printf("ONLY ONE IS ON PATROL.\n");
			printf("HE WALKS WEARILY FROM ONE SIDE OF THE ROOM TO THE OTHER.\n");
			printf("HIS EYES ARE DULL, HIS UNIFORM DIRTY.\n");
		}
		print_medium_pause("THERE IS A DOOR ACROSS THE ROOM");
		printf("\n");

		printf("YOU CAN...\n");
		printf("look\n");
		if (!knocked_out_guard) {printf("knock out guard\n");}
		if (!knocked_out_guard) {printf("sneak by\n");}
		if (knocked_out_guard)  {printf("leave\n");}
		what_do_you_do();

		scanf("%19[^\n]s", &action[0]);

		if (compare_characters(action, "knock out guard") == true) {
			print_medium_pause("YOU WALK UP SLOWLY BEHIND THE GUARD.");
			if(have_torch) {print_medium_pause("THE BUTT OF YOUR TORCH HITS TRUE.");}
			if(!have_torch) {print_medium_pause("YOU STRIKE HIM HARD, ONCE ON THE HEAD.");}
			print_medium_pause("HE CRUMPLES TO THE GROUND WITH A SOFT THUD.");

			knocked_out_guard = true;
		}

		if (compare_characters(action, "sneak by") == true) {
			printf("YOU SNEAK BY, OUT OF THE DUNGEON.\n");
			printf("YOU WIN!!!!!\n");
			return EXIT_SUCCESS;
		}

		if (compare_characters(action, "leave") == true) {
			print_medium_pause("YOU ESCAPE THE DUNGEON! YOU WIN!!!\n");

			return EXIT_SUCCESS;
		}

		strcpy(action, "");
		fflush(stdin);
	}

	


//~~~~~~~~~~~~~~~~~~ROOM FOUR: HEART LAIR~~~~~~~~~~~~~~~~~~~~~~~~~
	bool player_has_gone_mad = false;

	while (strcmp(current_location, "HEART_LAIR") == 0) {
		print_medium_pause("THE HEART OF THE CASTLE BEATS HERE.");
		print_medium_pause("YOU CAN FEEL ITS THRUM IN THE SOLES OF YOUR FEET.");
		print_medium_pause("IT WAS A MISTAKE TO COME HERE.");

		printf("YOU CAN:\n");
		if (!player_has_gone_mad) {printf("resist\n");}
		if (!player_has_gone_mad) {printf("go mad\n");}
		if (!player_has_gone_mad) {printf("succumb\n");}
		if (player_has_gone_mad)  {printf("speak?\n");}

		scanf("%19[^\n]s", &action[0]);
		
		if (compare_characters(action, "resist") == true) {
			print_long_pause("YOU GRIT YOUR TEETH UNTIL THEY CRACK.");
			print_medium_pause("THE HEART BEATS AND BEATS AND BEATS");
			print_medium_pause("IT SHAKES YOUR BONES.");
			print_medium_pause("YOU FEEL THEM SPLINTER AND CRACK.");
			print_long_pause("FOOL. YOU SHOULD NOT HAVE COME.");
			printf("YOU HAVE DIED! YOU LOSE(?)\n");

			return EXIT_SUCCESS;
		}

		if (compare_characters(action, "succumb") == true) {
			print_long_pause("THE HEART ROARS IN YOUR EARS.");
			print_medium_pause("YOU DON\'T TRY TO FIGHT IT.");
			print_medium_pause("THIS WAS EASIER. IT PULLS YOU SOFTLY INTO THE DARK.");
			printf("YOU HAVE DIED! YOU LOSE(?)\n");
			
			return EXIT_SUCCESS;
		}

		if (compare_characters(action, "go mad") == true) {
			print_long_pause("YOU LET YOUR MIND SPLINTER AND BREAK.");
			print_medium_pause("THANK GOD FOR THAT.");
			print_medium_pause("THE HEART IS ABLE TO SPEAK TO YOU.");
			print_medium_pause("\"little warrior.\"");
			print_medium_pause("\"firey one. what brings you to the dungeon\'s deep?\"");
		
			player_has_gone_mad = true;
			fflush(stdin);
			strcpy(action, "");
		}

		if (compare_characters(action, "speak?") == true) {
			print_medium_pause("YOU TELL THE HEART THAT YOU CANNOT REMEMBER.");
			print_medium_pause("\"poor warrior. they emptied your head.\"");
			print_medium_pause("I can give back what they took from you.");
			print_medium_pause("THE THRUM ENVELOPS YOU.");
			print_medium_pause("YOU REMEMBER SOMETHING ONCE FORGOTTEN.");

			printf("\nYOU WIN! YOU RETRIVED A MEMORY!\n");

			return EXIT_SUCCESS;
		}

		fflush(stdin);
		strcpy(action, "");
	}


	return EXIT_SUCCESS;
}