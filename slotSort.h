/*
 * slots.h
 *
 *  Created on: 3 Mar 2017
 *	Edited on: 6 Mar 2017
 *      Author: kiowa + lorenzo
 */
#ifndef SLOTS_H
#define SLOTS_H
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void slotFill(int slotCount, char slotArr[20][100]);
void slotAssign(int playerCount, int slotCount,struct players_ player[], char slotArr[20][100]);

void slotFill(int slotCount, char slotArr[20][100]){


	int i, r;

	srand(time(NULL)); // start random number generator with time from CPU as source

	for(i = 0; i < slotCount; i++){

		r = rand() % 3; // random number between 0 and 2
		switch(r){
			case 0: strcpy(slotArr[i], "ground\n"); break;
			case 1: strcpy(slotArr[i], "hill\n"); break;
			case 2: strcpy(slotArr[i], "city\n"); break;
					
		}
	}
}

void slotAssign(int playerCount, int slotCount,struct players_ player[], char slotArr[20][100]){

	int i, j;
	int x;
	int temp[playerCount];
	int duplicate = 1;

	srand(time(NULL));

	while(duplicate == 1){ // code from previous assignment that does not allow duplicates
		for (i = 0; i < playerCount; i++){
			x = rand() % slotCount;
			temp[i] = x;
		}
		duplicate = 0;
		for(i = 0; i < playerCount; i++){
			for(j = i + 1; j < playerCount; j++){
				if(temp[i] == temp[j]){
					duplicate = 1; break; // if there are, duplicate remains 1
				}
			}
		}
		if(!duplicate){
			break; // if not, while loop terminates
		}
	}
	
	for(i = 0; i < playerCount; i++){
		player[i].slotNum = temp[i] + 1;
		
		if(slotArr[i] == "ground"){
			player[i].slotType = 0;
		}
		else if(slotArr[i] == "hill"){
			player[i].slotType = 1;
		}
		else if(slotArr[i] == "city"){
			player[i].slotType = 2;
		}
		
	}
}
#endif /* SLOTS_H */

