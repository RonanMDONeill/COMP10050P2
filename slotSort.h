/*
 * slots.h

 *
 *  Created on: 3 Mar 2017
 *      Author: kiowa + lorenzo
 */
#ifndef SLOTS_H
#define SLOTS_H
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include "structs.h"

void slotFill(int slotCount);
void slotAssign(int playerCount, int slotCount,struct players_ player[]);

void slotFill(int slotCount){


	int i, r;

	srand(time(NULL)); // start random number generator with time from CPU as source

	for(i = 0; i < slotCount; i++){

		r = rand() % 3; // random number between 0 and 2
		switch(r){
			case 0: player[i].slotType = 0; break;
			case 1: player[i].slotType = 1; break;
			case 2: player[i].slotType = 2; break;
		}
	}
}

void slotAssign(int playerCount, int slotCount,struct players_ player[]){

	int i, j;
	int x;
	int temp[7];

	srand(time(NULL));

	for(i = 0; i < playerCount; i++){
		x = rand() % slotCount;
		for(j = 0; j < playerCount; j++){
			while(temp[j] == x){
				x = rand() % slotCount + 1;
			}
		}
		player[i].slotNum = x + 1;
		temp[i] = x;
	}

}
#endif





