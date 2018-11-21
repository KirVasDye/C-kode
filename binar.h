#include<stdio.h>
#include<math.h>

unsigned short digitBinar(unsigned int a) {
	unsigned short res = 0;
	while (a > 0) {
		res++;
		a /= 2;
	}
	return res;
}

unsigned int shifrBinar(unsigned int a) {
	unsigned int res = 0;
	int i;
	for (i = (sizeof(unsigned int) * 8 - 1); i >= 0; i -=2) {
		res |= a / (unsigned int)pow(2, i);
		res *= 2;
		a %= (unsigned int)pow(2, i);
		res |= a / (unsigned int)pow(2, i - 1);
		res *= 2;
	}
	return res;
}

void printAsBinar(unsigned int a) {
	for (int i = sizeof(unsigned int) * 8 - 1; i >= 0; i--) {
		unsigned int mask = (1 << i);
		if (a & mask)
			printf("1");
		else
			printf("0");
	}
	printf("\n");
}

unsigned int sdvigRBinar(unsigned int a, int n) {
	unsigned int buf;
	int i;
	for (i = 0; i < n; i++) {
		buf = (a % 2)<< (sizeof(unsigned int) * 8 - 1);
		a >>= 1;
		a |= buf;
	}
	return a;
}
