#include"takenBig.h"
int main(void) {
	int i, j, n;
	printf("Enter n * n : ");
	scanf("%d", &n);
	unsigned short** arr = (unsigned short**)malloc(n * sizeof(unsigned short*));
	for (i = 0; i < n; i++)
		arr[i] = (unsigned short*)malloc(n * sizeof(unsigned short));

	fullTaken(arr, n);
	if (!exists(arr, n)) {
		unsigned int tmp = arr[0][0];
		arr[0][0] = arr[0][1];
		arr[0][1] = tmp;
	}
	printArr(arr, n);
	printf("You can use 'w','a','s','d' to movment\n");
	findZero(arr, n, i, j);
	char move;
	while (!final(arr, n)) {
		move = getchar();
		switch (move) {
		case 'w':
			if (upR(i, n)) {
				up(arr, i, j);
				printArr(arr, n);
			}
			else
				printf(ERROR);
			break;
		case 's':
			if (downR(i, n)) {
				down(arr, i, j);
				printArr(arr, n);
			}
			else
				printf(ERROR);
			break;
		case 'd':
			if (rightR(j, n)) {
				right(arr, i, j);
				printArr(arr, n);
			}
			else
				printf(ERROR);
			break;
		case 'a':
			if (leftR(j, n)) {
				left(arr, i, j);
				printArr(arr, n);
			}
			else
				printf(ERROR);
			break;
		}
	
	}

	for (i = 0; i < n; i++)
		free(arr[i]);
	free(arr);
	return 0;
}
