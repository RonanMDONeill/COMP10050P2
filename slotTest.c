#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include "slotsort.h"

int main(void){
	
	int playerCount, slotCount, x;
	char slotArr[20][100], // the completed player struct will be defined here, or already before
	
	printf("Slots: ");
	scanf("%d", &slotCount);
	printf("Players: ");
	scanf("%d", &playerCount);
	
	slotFill(slotCount, slotArr);
	slotAssign(playerCount, slotCount, slotArr, player.slotType, player.slotNum);
	
	for(x = 0; x < playerCount; x++){
		printf("%s is at %d %s", player[x].name, player[x].slotNum, player[x].slotType);
	}
	
	return 0;
}