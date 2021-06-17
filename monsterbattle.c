#include <stdio.h>
#include <stdlib.h>
#include<time.h>
#include "monsterbattle.h"

int getRandomNumber2(int min, int max) {
	
	int num = max - min + 1;
	
	int val = (rand() % num) + min;
	
	return val;
}

void fillRooms(Room rooms[], int roomNumber) {
	
	int val = getRandomNumber();
	
	if (val == 4) {
		(rooms[roomNumber]).type = EMPTY;
	}

	if (val < 4) {
		(rooms[roomNumber]).type = PRIZE;
		(rooms[roomNumber]).prize.points = (rand() % 11) + 5;
	}
	
	if (val > 4) {
		(rooms[roomNumber]).type = MONSTER;
		(rooms[roomNumber]).monster.hitPoints = getRandomNumber2(10, 30);
		
		if ((rooms[roomNumber]).monster.hitPoints % 3 == 0) {
			(rooms[roomNumber]).monster.experiencePoints = 3;
		} else {
			(rooms[roomNumber]).monster.experiencePoints = 1;
		}
	}
	
	
}

int getRandomNumber() {
    
	int val = ((rand() % 11) + 0);
	
	return val;
}

void enterRoom(Room room[], int roomNumber, Character player, int *resultHP, int *resultXP) {
	
	if (room[roomNumber].type == EMPTY) {
		printf("Room is empty\n");
		*resultHP = 0;
		*resultXP = 0;
	}
	
	if (room[roomNumber].type == MONSTER) {
		printf("This room has a monster!\n");
		int xpChange = room[roomNumber].monster.experiencePoints;
		int hpLost;
		room[roomNumber].monster.hitPoints = getRandomNumber2(10, 30);
		
		hpLost = abs((player.experiencePoints - room[roomNumber].monster.hitPoints));
		
		*resultHP = hpLost;
		*resultXP = xpChange;
	}
	if (room[roomNumber].type == PRIZE) {
	    
	    int prizeVal = getRandomNumber2(5, 15);
		printf("This room has a prize of %d!!!\n", prizeVal);
		*resultHP = 0;
		*resultXP = 0;
	}
	
}

void printCharacter(Character  c) {
	
	printf("PLAYER (HP: %d, XP: %d)\n", c.hitPoints, c.experiencePoints);
	
}