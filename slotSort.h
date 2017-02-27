void slotFill(int slotCount, char slotArr[20][100]);
void slotAssign(int playerCount, int slotCount, char slotArr[20][100], char player.slotType[6][100], int player.slotNum[6][100]);

void slotFill(int slotCount, char slotArr[20][100])
{
	int x, m;

	srand(time(NULL)); // start random number generator with time from CPU as source
	
	for(x = 0; x < slotCount; x++){
		m = rand() % 3; // random number between 0 and 2
		switch(m){
			case 0: strcpy(slotArr[x], "Ground\n"); break;
			case 1: strcpy(slotArr[x], "Hill\n"); break;
			case 2: strcpy(slotArr[x], "City\n"); break;
		}
	}		
}

void slotAssign(int playerCount, int slotCount, char slotArr[20][100], char player.slotType[6][100], int player.slotNum[6][100])
{
	int x, y;
	int i;
	int check[6];
	
	srand(time(NULL));
	
	for(x = 0; x < playerCount; x++){
		i = rand() % slotCount;
		for(y = 0; y < playerCount; y++){
			while(check[y] == i){
				i = rand() % slotCount;
			}
		}
		strcpy(player[x].slotType, slotArr[i]);
		player[x].slotNum = i + 1;
		check[x] = i;
	}
	
}