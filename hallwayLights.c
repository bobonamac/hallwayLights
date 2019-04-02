// calculates the Car Talk puzzler of which light is left on in the hallway

#include<stdbool.h>
#include<stdio.h>
#include<string.h>

// prototypes
int promptPosInt();
void flipAndPrint(bool hallwayBulbs[], int bulbs);

/***********************************************/

int main(void) {
	int bulbs = promptPosInt();
	bool hallwayBulbs[bulbs];

	for (int i = 0; i < bulbs; ++i)
	{
		hallwayBulbs[i] = false;
	}
	printf("\n");

	// print the hallway with all the lights off
	for (int j = 0; j < bulbs; j++) {
		printf("%s ", hallwayBulbs[j] ? "o" : "_");
	}
	printf("\n");
	// execute the chain pulls, print, and list bulbs left on
	flipAndPrint(hallwayBulbs, bulbs);

	return 0;
}

/***********************************************/

int promptPosInt() {
	int n;
	do {
		printf("\nHow many lightbulbs? ");
		scanf("%d", &n);
	}
	while (n < 1);

	return n;
}

/***********************************************/

void flipAndPrint(bool hallwayBulbs[], int bulbs) {
	printf("\n");
	// do this bulb number of times
	for (int everyNthChain = 1; everyNthChain < bulbs + 1; everyNthChain++) {

		// start with Nth chain and increment by the same till bulbs is reached
		for (int i = everyNthChain; i <  bulbs + 1; i += everyNthChain) {
			hallwayBulbs[i - 1] = !hallwayBulbs[i - 1];	
		}	
		// print each of the elements
		for (int j = 0; j < bulbs; j++) {
			printf("%s ", hallwayBulbs[j] ? "o" : "_");
		}
		// space between runs
		printf("\n\n");
	}
	// print list of bulbs left on
	printf("Bulbs left on: ");
	for (int k = 0; k < bulbs; k++) {
		if (hallwayBulbs[k] == true) {
			printf("%d", k + 1);	
		}
		if (k != bulbs - 1 && hallwayBulbs[k] == true) {
				printf(", ");
		}
	}

	printf("\n\n\n");

	return;
}