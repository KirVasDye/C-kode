#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef unsigned int u_int;

typedef struct myStak {                            // Создание структуры стека
	int stak[1000];
	u_int top;
} myStak;

void createStak(myStak* pstak) {                   // Создание стека
	pstak->stak[0] = 100;
	pstak->top = 0;
	return;
}

void delTop(myStak* pstak) {                       // Удаление верхнего элемента
	if(pstak->top - 1 < 0) {
		printf("Error\n");
		exit(-1);
	}
	pstak->top = pstak->top - 1;
	return;
}

void push(myStak* pstak, int simbol) {            // Ввод элемента в стек
	if(pstak->top + 1 == 999) {
		printf("Error, stak overflow\n");
		exit(-1);
	}
	pstak->top = pstak->top + 1;
	pstak->stak[pstak->top] = simbol;
	return;
}

bool stakIsEmpty(myStak pstak) {                   // Проверка на пустоту стека
	bool res;
	if(pstak.top == 0)
		res = true;
	else
		res = false;
	return res;
}

void convert(char ch, int* res) {                            // Функция конвертации скобок в удобное представление
	switch(ch) {
		case '(':
			*res = 1;
			break;
		case ')':
			*res = 2;
			break;
		case '{':
			*res = 3;
			break;
		case '}':
			*res = 4;
			break;
		case '[':
			*res = 5;
			break;
		case ']':
			*res = 6;
			break;
	}
	return;
}

int main(void) {

	myStak arr;
	createStak(&arr);
	char ch;
	int code;
	printf(" You can enter '()', '{}', '[]'\n and '0' for escepe\n");

	while(true) {

		scanf("%c", &ch);
		if(ch == '0')
			break;

		convert(ch, &code);

		if(code % 2 == 1)
			push(&arr, code);
		else if(code - arr.stak[arr.top] == 1)
				delTop(&arr);
			else
				break;
	}

	if(stakIsEmpty(arr))
		printf("True!\n");
	else
		printf("False\n");

	return 0;
}
