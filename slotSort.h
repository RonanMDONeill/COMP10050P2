/*
 * slots.h
 *
 *  Created on: 3 Mar 2017
 *      Author: kiowa + rónan
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
	int temp[7];

	srand(time(NULL));

	for(i = 0; i < playerCount; i++){
		x = rand() % slotCount;
		for(j = 0; j < playerCount; j++){
			while(temp[j] == x){
				x = rand() % slotCount;
			}
		}
		if(slotArr[x] == "ground"){
			player[x].slotType = 0;
		}
		else if(slotArr[x] == "hill"){
			player[x].slotType = 1;
		}
		else if(slotArr[x] == "city"){
			player[x].slotType = 2;
		}
		player[i].slotNum = x + 1;
		temp[i] = x;
	}

}
#endif

