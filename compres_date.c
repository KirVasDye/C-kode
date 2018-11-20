#include"kurs.h"
#include<stdio.h>


int main(void) {

	Date date;
	datec_t datec;

	// Ввод даты
	printf("Enter date day is ");
	scanf("%u", &date.dd);
	printf("Enter date mounth is ");
	scanf("%u", &date.mm);
	printf("Enter date year is ");
	scanf("%u", &date.yy);
	datec = compressDate(date);

	// Вывод даты

	printDate(date);
	printCompressedDate(datec);

	// Установка нового дня

	datec_t a;
	printf("Enter new date day is ");
	scanf("%u", &a);
	datec = setDay(datec, a);
	date = uncompressDate(datec);
	printDate(date);
	printCompressedDate(datec);

	// Установка нового месяца

	Month m;
	printf("Enter new date mounth is ");
	scanf("%u", &m);
	datec = setMonth(datec, m);
	date = uncompressDate(datec);
	printDate(date);
	printCompressedDate(datec);

	// Установка нового года

	datec_t y;
	printf("Enter new date year is ");
	scanf("%u", &y);
	datec = setYear(datec, y);
	date = uncompressDate(datec);
	printDate(date);
	printCompressedDate(datec);

	return 0;
}
