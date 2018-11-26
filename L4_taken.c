#include"taken.h"

int main(void) {
	// Begin
	fullTaken();
	if (!exists()) {
		unsigned short tmp = taken[0][0];
		taken[0][0] = taken[0][1];
		taken[0][1] = tmp;
	}
	for (int k = 0; k < 4; k++)
		for (int n = 0; n < 4; n++)
			if (taken[k][n] == 0) {
				i = k;
				j = n;
			}
	char move;
	printf("You can use 'w','a','s','d' to movment\n");
	printArr();
	while (!final()) {
		move = getchar();
		if (move == 'w') {
			up();
			printArr();
		}
		if (move == 's') {
			down();
			printArr();
		}
		if (move == 'd') {
			right();
			printArr();
		}
		if (move == 'a'){
			left();
			printArr();
		}
	}
	// End.
	return 0;
}
