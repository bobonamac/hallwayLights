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
	
	// print the hallway with all the lights off
	for (int printElementCounter = 0; printElementCounter < bulbs; printElementCounter++) {
		printf("%s ", hallwayBulbs[printElementCounter] ? "o" : "_");
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

	for (int everyNthChain = 1; everyNthChain < bulbs + 1; everyNthChain++) {

		// flip all the appropriate switches
		for (int bulbSwitchCounter = everyNthChain; bulbSwitchCounter <  bulbs + 1; bulbSwitchCounter += everyNthChain) {
			hallwayBulbs[bulbSwitchCounter - 1] = !hallwayBulbs[bulbSwitchCounter - 1];	
		}	
		// print each of the elements
		for (int printElementCounter = 0; printElementCounter < bulbs; printElementCounter++) {
			printf("%s ", hallwayBulbs[printElementCounter] ? "o" : "_");
		}
		// space between runs
		printf("\n\n");
	}
	// print list of bulbs left on
	printf("Bulbs left on: ");
	for (int i = 0; i < bulbs; i++) {
		if (hallwayBulbs[i] == true) {
			printf("%d", i + 1);	
		}
		if (i != bulbs - 1 && hallwayBulbs[i] == true) {
				printf(", ");
		}
	}

	printf("\n\n");

	return;
}