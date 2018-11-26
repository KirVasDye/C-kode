#include"taken.h"

int main(void) {
	// Begin
	fullTaken();
	if (!exists()) {
		unsigned short tmp = taken[0][0];
		taken[0][0] = taken[0][1];
		taken[0][1] = tmp;
	}
	findZero();
	char move;
	printf("You can use 'w','a','s','d' to movment\n");
	printArr();
	while (!final()) {
		move = getchar();
		if (move == 'w') {
			if (upR()) {
				up();
				printArr();
			}
			else
				printf(ERROR);
		}
		if (move == 's') {
			if (downR()) {
				down();
				printArr();
			}
			else
				printf(ERROR);
		}
		if (move == 'd') {
			if (rightR()) {
				right();
				printArr();
			}
			else
				printf(ERROR);
		}
		if (move == 'a'){
			if (leftR()) {
				left();
				printArr();
			}
			else
				printf(ERROR);
		}
	}
	// End.
	return 0;
}
