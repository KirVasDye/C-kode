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
        unsigned int mask1, mask2;
        for(mask1 = 1, mask2 = 2; mask1 != 0; mask1 <<= 2, mask2  <<= 2) {
	res |= ((a & mask1) << 1) | ((a & mask2) >> 1);
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
