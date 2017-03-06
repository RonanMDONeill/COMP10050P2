/*
 *
 *	moveTest.c
 *  Created on: 6 Mar 2017
 *	Author: rónan
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "structs.h"
#include "slotSort.h"
#include "move.h"


int main(void){
	
	int playerCount, slotCount;
	int i, m, x, y, z;
	int opt = 5;
	int diff, closest, track1, track2, mark, choice;
	char temp[70];
	char slotArr[20][100];
	
	for(x = 0; x < playerCount; x++){
		
		movePlayer(playerCount, slotCount, player, slotArr, &opt, x);

		switch(opt){ // switch statement
			case 1: strcpy(temp, slotArr[player[x].slotNum + 1]);
					if(temp == "ground"){ // replace current slot type with one ahead of it
						player[x].slotType = 1;
					}
					else if(temp == "hill"){
						if(player[i].Dexterity < 50){
							player[i].strength -= 10;
							if(player[i].strength < 0){
								player[i].strength = 0;
							}
						}
						else if(player[i].Dexterity >= 60){
							player[i].strength += 10;
							if(player[i].strength > 100){
								player[i].strength = 100;
							}
						}
						player[x].slotType = 2;
					}
					else if(temp == "city"){
						if(player[i].smartness > 50){
							player[i].magic_Skills += 10;
							if(player[i].magic_Skills > 100){
								player[i].magic_Skills = 100;
							}
						}
						else if(player[i].smartness <= 50){
							player[i].Dexterity -= 10;
							if(player[i].Dexterity < 0){
								player[i].Dexterity = 0;
							}
						}
						player[x].slotType = 3;
					} 
					player[x].slotNum += 1; break; // increase the slot number by one
					
			case 2: strcpy(temp, slotArr[player[x].slotNum - 1]);
					if(temp == "ground"){ // replace current slot type with one behind of it
						player[x].slotType = 1;
					}
					else if(temp == "hill"){
						player[x].slotType = 2;
					}
					else if(temp == "city"){
						player[x].slotType = 3;
					} 
					player[x].slotNum -= 1; break; // decrease slot number by one
					
			case 3: closest = 30;
					diff = 30;
					track1 = 30;
					track2 = 30;
					mark = 5;
					for(z = 0; z < playerCount; z++){ // find closest player(s)
						diff = abs(player[x].slotNum - player[z].slotNum); // absolute value of the difference between players
						if(diff == 0){
							diff = 30;
						}
						
						if(diff < closest){ // set closest
							closest = diff;
							track1 = z;
							mark = 1;
						}
						else if(diff == closest){ // if there are 2 closest
							track2 = z;
							mark = 2;
						}
					}
					
					if(mark == 1){
						if(player[track1].strength <= 70){
							player[track1].life -=  (0.5) * player[track1].strength;
						}
						else if(player[track1].strength > 70){
							player[x].life -= (0.3) * player[track1].strength;
						}
					}
					else if(mark == 2){
						printf("There are two closest players.\nWould you like to attack:\n1. %s (Strength = %d LP = %.0f)?\n2.%s (Strength = %d LP = %.0f)?\n", player[track1].name, player[track1].strength, player[track1].life, player[track2].name, player[track2].strength, player[track2].life);
						scanf("%d", &choice);
						while(choice < 1 || choice > 2){
							printf("Sorry, not a valid option, please try again: ");
							scanf("%d", &choice);
						}
						
						if(choice == 1){
							if(player[track1].strength <= 70){
								player[track1].life -=  (0.5) * player[track1].strength;
							}
							else if(player[track1].strength > 70){
								player[x].life -= (0.3) * player[track1].strength;
							}
						}
						else if(choice == 2){
							if(player[track2].strength <= 70){
								player[track2].life -=  (0.5) * player[track2].strength;
							}
							else if(player[track2].strength > 70){
								player[x].life -= (0.3) * player[track2].strength;
							}
						}
					} break;
		}
	}
	
	for(x = 0; x < playerCount; x++){
		printf("%s -> %.0f -> %d (%s)\n", player[x].name, player[x].life, player[x].slotNum, slotArr[player[x].slotNum-1]);
	}
	
	return 0;
}
