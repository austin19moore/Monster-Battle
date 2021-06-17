#ifndef MONSTERBATTLE_H
#define MONSTERBATTLE_H

typedef enum TYPE {EMPTY, PRIZE, MONSTER} TYPE;

typedef struct Character_struct {
   
   int hitPoints;
   int experiencePoints;
   
} Character;

typedef struct Prize_struct {
 int points;   
} Prize;



typedef struct Room_struct
{
    TYPE type;
    Character monster;
    Prize prize;
} Room;

int getRandomNumber2(int min, int max);

void fillRooms(Room rooms[], int roomNumber);

int getRandomNumber();

void enterRoom(Room room[], int roomNumber, Character player, int *resultHP, int *resultXP);

void printCharacter(Character  c);

#endif