/*
 *
 *	move.h
 *  Created on: 6 Mar 2017
 *	Author: rónan
 *
 */
 
#ifndef MOVE_H
#define MOVE_H
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void movePlayer(int playerCount, int slotCount,struct players_ player[], char slotArr[20][100], int *optPtr, int x);

void movePlayer(int playerCount, int slotCount,struct players_ player[], char slotArr[20][100], int *optPtr, int x){
	
	int opt = *optPtr;
	int y;
	int check1 = 0, check2 = 0, taken1, taken2;
		
	for(y = 0; y < playerCount; y++){ // check the slot before and after to see if it is full
		if(player[x].slotNum != slotCount && player[y].slotNum == (player[x].slotNum + 1)){
			check1 = 1;
			taken1 = y;
		}
		if(player[x].slotNum != 1 && player[y].slotNum == (player[x].slotNum - 1)){
			check2 = 1;
			taken2 = y;
		}
	}
		
	if(check1 != 1 && check2 != 1 && player[x].slotNum != slotCount && player[x].slotNum != 1){ // all options available
		printf("%s - would you like to:\n1. Move forwards?\n2. Move backwards?\n3. Attack closest player?\n", player[x].name);
		scanf("%d", &opt);
		while(opt < 1 || opt > 3){
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
		
	if(check1 == 1 && player[x].slotNum == 1){ // Slot ahead taken, also at first slot
		printf("%s - would you like to:\n1. You cannot move forwards, slot taken by %s.\n2. You cannot move backwards from here.\n3. Attack closest player?\n", player[x].name, player[taken1].name);
		scanf("%d", &opt);
		while(opt != 3){ 
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
	if(check2 == 1 && player[x].slotNum == slotCount){ // Slot behind taken, also at last slot
		printf("%s - would you like to:\n1. You cannot move forwards from here.\n2. You cannot move backwards, slot taken by %s.\n3. Attack closest player?\n", player[x].name, player[taken2].name);
		scanf("%d", &opt);
		while(opt != 3){ 
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
		
	if(check1 == 1 && check2 != 1 && player[x].slotNum != 1){ // Slot ahead taken
		printf("%s - would you like to:\n1. You cannot move forwards, slot taken by %s.\n2. Move Backwards?\n3. Attack closest player?\n", player[x].name, player[taken1].name);
		scanf("%d", &opt);
		while(opt < 2 || opt > 3){
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
	if(check2 == 1 && check1 != 1 && player[x].slotNum != slotCount){ // Slot behind taken
		printf("%s - would you like to:\n1. Move forwards?\n2. You cannot move backwards, slot taken by %s.\n3. Attack closest player?\n", player[x].name, player[taken2].name);
		scanf("%d", &opt);
		while(opt < 1 || opt > 3 || opt == 2){
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
	if(check1 == 1 && check2 == 1 && player[x].slotNum != slotCount && player[x].slotNum != 1){ // Slot ahead and behind taken
		printf("%s - would you like to:\n1. You cannot move forwards, slot taken by %s.\n2. You cannot move backwards, slot taken by %s.\n3. Attack closest player?\n", player[x].name, player[taken1].name, player[taken2].name);
		scanf("%d", &opt);
		while(opt != 3){ 
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
		
	if(player[x].slotNum == slotCount && check2 != 1){ // At last slot
		printf("%s - would you like to:\n1. You cannot move forwards from here.\n2. Move backwards?\n3. Attack closest player?\n", player[x].name);
		scanf("%d", &opt);
		while(opt < 2 || opt > 3){
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
	if(player[x].slotNum == 1 && check1 != 1){ // At first slot
		printf("%s - would you like to:\n1. Move forwards?\n2. You cannot move backwards from here.\n3. Attack closest player?\n", player[x].name);
		scanf("%d", &opt);
		while(opt < 1 || opt > 3 || opt == 2){
			printf("That is not a valid option, try again: ");
			scanf("%d", &opt);
		}
	}
		
	*optPtr = opt;
}

#endif /* MOVE_H */
