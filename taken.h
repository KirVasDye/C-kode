#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>

#define ERROR "You cant move at this direction\n"

unsigned short taken[4][4];
int i, j;

void findZero() {
	for (int k = 0; k < 4; k++)
		for (int n = 0; n < 4; n++)
			if (taken[k][n] == 0) {
				i = k;
				j = n;
			}
	return;
}

// Create function for move, were <i> and <j> is index zero

void up() {
	taken[i][j] = taken[i - 1][j];
	taken[i - 1][j] = 0;
	i--;
	return;
}

void down() {
	taken[i][j] = taken[i + 1][j];
	taken[i + 1][j] = 0;
	i++;
	return;
}

void right() {
	taken[i][j] = taken[i][j + 1];
	taken[i][j + 1] = 0;
	j++;
	return;
}

void left() {
	taken[i][j] = taken[i][j - 1];
	taken[i][j - 1] = 0;
	j--;
	return;
}

bool leftR() {
	return j - 1 == -1 ? false : true;
}

bool rightR() {
	return j + 1 == 4 ? false : true;
}

bool upR() {
	return i - 1 == -1 ? false : true;
}

bool downR() {
	return i + 1 == 4 ? false : true;
}


/*=========================================================*/

// Print array on screen

void printArr() {
	int k, l;
	for (k = 0; k < 4; k++) {
		for (l = 0; l < 4; l++) {
			printf("\t%d", taken[k][l]);
		}
		printf("\n\n");
	}
	return;
}

/*=========================================================*/

bool final() {
	bool res = true;
	int k, l, sum = 1;
	for (k=0;k<4;k++)
		for (l = 0; l < 4; l++) {
			if (taken[k][l] != sum % 16) {
				res = false;
				break;
			}
			sum++;
		}
	return res;
}

/*=========================================================*/

void fullTaken() {
	int n, x, k = 0;
	srand(time(NULL));
	int arr[16];
	bool alreadyThere;
	for (n = 0; n < 16; ) {
		alreadyThere = false;
		int newRanomValue = rand() % 16;
		for (x = 0; x < n; x++) {
			if (arr[x] == newRanomValue) {
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere) {
			arr[n] = newRanomValue;
			n++;
		}
	}
	for (n = 0; n < 4; n++)
		for (x = 0; x < 4; x++) {
			taken[n][x] = arr[k];
			k++;
		}
	return;
}

bool exists() {
	int x, y, k = 0;
	int inv = 0;
	int* arr;
	bool res;
	arr = (int*)malloc(16 * sizeof(int));

	for (x = 0; x < 4; x++)
		for (y = 0; y < 4; y++, k++)
			arr[k] = taken[x][y];

	for (x = 0; x < 16; x++)
		for (y = 0; y < x; y++)
			if (arr[y] > arr[x])
				inv++;

	for (x = 0; x < 16; x++)
		if (arr[x] == 0) {
			inv += 1 + x / 4;
			break;
		}

	res = inv % 2 == 0 ? true : false;

	free(arr);

	return res;
}
