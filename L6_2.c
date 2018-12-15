#include <stdio.h>

void Cross(int size, char simbol) {
	int x, y;
	for(y = 0; y < size; y++) {
		for(x = 0; x < size; x++) {
			if(x == y || x == (size - y - 1))
				printf("%c", simbol);
			else
				printf(" ");
		}
		printf("\n");
	}
	return;
}

void EmptyDiamond(int size, char simbol) {
	int x, y;
	for(y = 0; y < size; y++) {
		for(x = 0; x < size; x++) {
			if(x == size/2 - y || x == size/2 + y || x == y - size/2 || x == 1.5 *(size - size%2) - y)
				printf("%c", simbol);
			else
				printf(" ");
		}
		printf("\n");
	}
	return;
}

void FilledDiamond(int size, char simbol) {
	int x, y;
	for(y = 0; y < size; y++) {
		for(x = 0; x < size; x++) {
			if(x >= size/2 - y && x <= size/2 + y && x >= y - size/2 && x <= 1.5 *(size - size%2) - y)
				printf("%c", simbol);
			else
				printf(" ");
		}
		printf("\n");
	}
	return;
}

typedef void (*funcForDrawing_t)(int, char);

int main(void) {
	funcForDrawing_t funcForDrawing[3];
	funcForDrawing[0] = Cross;
	funcForDrawing[1] = EmptyDiamond;
	funcForDrawing[2] = FilledDiamond;
	int size, n;
	char simbol;
	printf("Enter simbol : ");
	scanf("%c", &simbol);
	printf("Chose your figure : \n");
	printf("1) Cross\n2) Empty Diamond\n3) FilledDiamond\nEnter num : ");
	scanf("%d", &n);
	printf("Enter size : ");
	scanf("%d", &size);
	funcForDrawing[n](size, simbol);
	return 0;
}
