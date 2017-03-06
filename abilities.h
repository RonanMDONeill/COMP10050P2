/*
 * abilitties.h
 *
 *  Created on: 5 Mar 2017
 *      Author: kiowa
 */
#ifndef ABILITIES_H
#define ABILITIES_H
#include <stdio.h>
#include <time.h>
#include "structs.h"


void abilities(int playerCount, struct players_ player[]){
	int i;

    for(i=0;i<playerCount;i++){
    	if(player[i].class == Ogre){
    		player[i].smartness = rand()%21;
        	player[i].Luck = 50 - player[i].smartness;
        	player[i].strength = 80 - rand()%21;
        	player[i].magic_Skills = 0;
        	player[i].Dexterity = 80 + rand()%21;
		player[i].life = 100;
         }


        else if(player[i].class == Wizard){
        		player[i].smartness =  90 + rand()%11;
        		player[i].Luck = 50 + rand()%51;
        		player[i].strength = rand()%21;
        		player[i].magic_Skills = 80 + rand()%21;
        		player[i].Dexterity = rand()%101;
			player[i].life = 100;

        	}
        else if(player[i].class == Elf){
        		player[i].smartness = 70 + rand()%30;
        	    player[i].Luck = 60 + rand()%41;
        	    player[i].strength = rand()%51;
        	    player[i].magic_Skills = 50 + rand()%31;
        	    player[i].Dexterity = rand()%101;
		    player[i].life = 100;
        	}
        else if(player[i].class == Human){
                while(1){
                	player[i].smartness = rand()%101;
                	player[i].Luck = rand()%101;
                	player[i].strength = rand()%101;
                	player[i].magic_Skills = rand()%101;
                	player[i].Dexterity = rand()%101;
			player[i].life = 100;
                	if(player[i].smartness + player[i].Luck +player[i].strength +player[i].magic_Skills +player[i].Dexterity < 300){
                		break;
                	}
                }
        	}
    }
    while(player[i].slotType == hill){
    	if(player[i].Dexterity < 50){
    		player[i].strength -= 10;
    	}
    	else if(player[i].Dexterity >= 60){
    		player[i].strength +=10;
    	}
    }

    while(player[i].slotType == city){
    	if(player[i].smartness > 60){
    		player[i].magic_Skills += 0;

    	}
    	else if(player[i].smartness <= 50){
    		player[i].Dexterity -= 10;
    	}
    }
}

#endif
