// calculates the Car Talk puzzler of which light is left on in the hallway

#include <stdio.h>

/* 
	- prompt for a number of lightbulbs and store as numBulbs
	- create bool array with numBulbs elements set to off
	- print bulbs
	- loop cntr with numBulbsPasses w/ nested numBulbs cntr to flip elements
	- print after each loop
	- print element numbers left on
*/

// **************************************************************************80

/* 
makes a block of size prompted from user 
*/

#include<stdbool.h>
#include<stdio.h>
#include<string.h>

// prototypes
int promptPosInt();
void printHallway(bool hallwayBulbs[], int bulbs);

/***********************************************/

int main(void) {
	int bulbs = promptPosInt();
	bool hallwayBulbs[bulbs];

	for (int i = 0; i < bulbs; ++i)
	{
		hallwayBulbs[i] = false;
	}

	printHallway(hallwayBulbs, bulbs);

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

void printHallway(bool hallwayBulbs[], int bulbs) {
	printf("\n");

	// using bulbs + 1 to prevent 'Floating Point Exception' error
	for (int runCount = 1; runCount < bulbs + 1; runCount++) {

		// print each of the elements
		for (int elementCount = 0; elementCount < bulbs; elementCount++) {
			printf("%s ", hallwayBulbs[elementCount] ? "o" : "_");
		}
		// space between runs
		printf("\n");

		// print all bulbs to test
		for (int i = 0; i < bulbs; i++)
		{
			printf("%d ", hallwayBulbs[i]);
		}
		// space between runs
		printf("\n\n");

		// when runCount is 5 zB. if the flipCount is divisible by runCount, flip value
		// using bulbs + 1 to prevent 'Floating Point Exception' error
		// flip all the appropriate switches
		for (int flipCount = 0; flipCount < bulbs; flipCount++) {
			if (flipCount % runCount == 0) {
			hallwayBulbs[flipCount] = !hallwayBulbs[flipCount];	
			}	
		}
	}
	printf("\n");

	// print all bulbs to test
	for (int i = 0; i < bulbs; i++)
	{
		printf("%d ", hallwayBulbs[i]);
	}

	// space between runs
	printf("\n");

	// print list of bulbs left on
	printf("Bulbs left on: ");
	for (int i = 0; i < bulbs; i++) {
		if (hallwayBulbs[i] == true) {
			printf("%d ", i);
		}
	}
	printf("\nWhy the extra flip on element zero???\n");
	printf("\n\n");
	return;
}
