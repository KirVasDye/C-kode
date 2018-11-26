#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#include<stdbool.h>
#include<malloc.h>

#define ERROR "You cant move at this direction\n"

void up(unsigned short** taken, int& i, int& j) {
	taken[i][j] = taken[i - 1][j];
	taken[i - 1][j] = 0;
	i--;
	return;
}

void down(unsigned short** taken, int& i, int& j) {
	taken[i][j] = taken[i + 1][j];
	taken[i + 1][j] = 0;
	i++;
	return;
}

void right(unsigned short** taken, int& i, int& j) {
	taken[i][j] = taken[i][j + 1];
	taken[i][j + 1] = 0;
	j++;
	return;
}

void left(unsigned short** taken, int& i, int& j) {
	taken[i][j] = taken[i][j - 1];
	taken[i][j - 1] = 0;
	j--;
	return;
}

bool leftR(int j, int n) {
	return j - 1 == -1 ? false : true;
}

bool rightR(int j, int n) {
	return j + 1 == n ? false : true;
}

bool upR(int i, int n) {
	return i - 1 == -1 ? false : true;
}

bool downR(int i, int n) {
	return i + 1 == n ? false : true;
}

void printArr(unsigned short** taken, int n) {
	int i, j;
	for (i = 0; i < n; i++) {
		for (j = 0; j < n; j++) {
			printf("\t%d", taken[i][j]);
		}
		printf("\n\n");
	}
	return;
}

bool final(unsigned short** taken, int n) {
	bool res = true;
	int i, j, sum = 1;
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			if (taken[i][j] != sum % (n*n)) {
				res = false;
				break;
			}
			sum++;
		}
	return res;
}

void fullTaken(unsigned short** taken, int n) {
	int i, j, k = 0;
	srand(time(NULL));
	unsigned short* arr = (unsigned short*)malloc((n*n) * sizeof(unsigned short));
	bool alreadyThere;
	for (i = 0; i < (n*n); ) {
		alreadyThere = false;
		int newRanomValue = rand() % (n*n);
		for (j = 0; j < i; j++) {
			if (arr[j] == newRanomValue) {
				alreadyThere = true;
				break;
			}
		}
		if (!alreadyThere) {
			arr[i] = newRanomValue;
			i++;
		}
	}
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			taken[i][j] = arr[k];
			k++;
		}
	free(arr);
	return;
}

bool exists(unsigned short** taken, int n) {
	int i, j, k = 0;
	int inv = 0;
	unsigned short* arr = (unsigned short*)malloc((n*n) * sizeof(unsigned short));
	bool res;

	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++, k++)
			arr[k] = taken[i][j];

	for (i = 0; i < (n*n); i++)
		for (j = 0; j < i; j++)
			if (arr[j] > arr[i])
				inv++;

	for (i = 0; i < (n*n); i++)
		if (arr[i] == 0) {
			inv += 1 + i / 4;
			break;
		}

	res = inv % 2 == 0 ? true : false;

	return res;
}

void findZero(unsigned short** taken, int n, int& i, int& j) {
	for (int k = 0; k < n; k++)
		for (int m = 0; m < n; m++)
			if (taken[k][m] == 0) {
				i = k;
				j = m;
			}
	return;
}
