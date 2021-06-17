#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "monsterbattle.h"

int main(int argc, char* argv[])
{
	
    Character character1;
	int numRooms;
	int lastXP;
	int changeHP = 0;
	int i;
	int roomNumber = 1;
    srand(time(0));

	character1.hitPoints = 50;
	character1.experiencePoints = 0;
	
    printf("Welcome to the MONSTER BATTLE rooms v.1\n");
	printf("Enter the number rooms would you like to endure: ");
    scanf("%d", &numRooms);
    printf("You have chosen to endure %d rooms. Let the challenge begin.\n", numRooms);
	
	Room rooms[numRooms];
	
	for (i = 0; i < numRooms; i++) {
	
	fillRooms(rooms, i); // occupies the rooms
	
	}

	printCharacter(character1);
	
		for (i = 0; i < numRooms; i++) { // starts the game entering the room
		
		printf("\n");
		
		printf("---ROOM %d OF %d---\n", roomNumber, numRooms);
		roomNumber++;
		
		enterRoom(rooms, i, character1, &changeHP, &lastXP);
	
		printf("You lost %d hitpoints while in this room.\n", changeHP);
		
		if (lastXP > 0) {
			printf("Congratulations, you gained experience points in the last room!\n");
		}
		
		if (changeHP < 0) {
		 changeHP = 0;   
		}
		
		character1.hitPoints += lastXP;
		
		character1.hitPoints -= changeHP;
		
		if (character1.hitPoints < 1) {
			break;
		}
		
		character1.experiencePoints += lastXP;
		
				
		printCharacter(character1);
		
		}
	
	if (character1.hitPoints > 0) {
	    printf("\n");
		printf("Congratulations!!! you have completed all of the rooms!!!\n");
	} else {
	    printf("\n");
		printf("You have failed to complete all of the rooms :(\n");
	}
	
	
    return 0;
}