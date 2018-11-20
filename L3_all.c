#include<stdio.h>
#include"binar.h"

int main() {
	unsigned int a;
	printf("Enter number ");
	scanf("%u", &a);
	printAsBinar(a);
	unsigned int b = shifrBinar(a);
	printAsBinar(b);
	int n;
	printf("Enter sdvig ");
	scanf("%d", &n);
	b = sdvigRBinar(a, n);
	printAsBinar(b);
	return 0;
}
