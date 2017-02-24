#include <stdio.h>
#include <string.h>

int main(void){
	
	char a[10][100] = { 0 }, b[10][100] = { 0 };
	int x;
	int n;
	
	printf("Enter amount of players (Max 6):\n");
	scanf("%d", &n);
	while(n < 1 || n > 6){
		printf("Maximum of 6\n");
		scanf("%d", &n);
	}
	
	for(x = 0; x < n; x++){
		printf("Enter character %d name: ", x+1);
		scanf("%s", a[x]);
		printf("Enter character %d type: ", x+1);
		scanf("%s", b[x]);
	}
	printf("\n");
	for(x = 0; x < n; x++){
		printf("%s\t%s\n", a[x], b[x]);
	}
	
	return 0;
}