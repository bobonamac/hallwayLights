// calculates the Car Talk puzzler - which lights are left on in the hallway

#include<stdbool.h>
#include<stdio.h>
#include<string.h>

// function prototypes
int promptPosInt();
void printHallway(bool hallwayBulbs[], int bulbs);
void pullChains(bool hallwayBulbs[], int bulbs);
void bulbsLeftOn(bool hallwayBulbs[], int bulbs);

/***********************************************/

int main(void) {
	// prompt for number of lightbulbs in the hallway
	int bulbs = promptPosInt();

	// create and then initialize hallwayBulb array to "off" 
	bool hallwayBulbs[bulbs];
	for (int i = 0; i < bulbs; ++i)
	{
		hallwayBulbs[i] = false;
	}

	// space after prompt for number of bulbs
	printf("\n");

	// print the hallway with all the lights off
	printHallway(hallwayBulbs, bulbs);

	// execute the chain pulls
	pullChains(hallwayBulbs, bulbs);

	// print a list of bulbs left on
	bulbsLeftOn(hallwayBulbs, bulbs);

	return 0;
}

/*********************************************************************************************************************/
/*********************************************************************************************************************/

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

void printHallway(bool hallwayBulbs[], int bulbs) {

	// print a pictographic representation of the hallwayBulb array
	for (int j = 0; j < bulbs; j++) {
		printf("%s ", hallwayBulbs[j] ? "o" : "_");
	}
	// space between lines
	printf("\n\n");

	return;
}

/***********************************************/

void pullChains(bool hallwayBulbs[], int bulbs) {

	// do this "bulb" number of times
	for (int everyNthChain = 1; everyNthChain < bulbs + 1; everyNthChain++) {

		// start with Nth chain and increment by the same till "bulbs" is reached
		for (int i = everyNthChain; i <  bulbs + 1; i += everyNthChain) {
			hallwayBulbs[i - 1] = !hallwayBulbs[i - 1];	
		}	
		
		// print a pictographic representation of the hallwayBulb array
		printHallway(hallwayBulbs, bulbs);
	}
	
	return;
}

/***********************************************/

void bulbsLeftOn(bool hallwayBulbs[], int bulbs) {
	
	// print list of bulbs left on
	printf("Bulbs left on: ");

	for (int k = 0; k < bulbs; k++) {

		// if the bulb is "on", print the element number + 1 = bulb number
		if (hallwayBulbs[k] == true) {
			printf("%d", k + 1);
			printf(", ");	
		}
	}

	printf("and that's all.\n\n\n");

	return;
}