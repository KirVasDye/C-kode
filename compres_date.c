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

	printf("Enter new date day is ");
	scanf("%u", &date.dd);
	datec = setDay(datec, date.dd);
	date = uncompressDate(datec);
	printDate(date);
	printCompressedDate(datec);

	// Установка нового месяца

	printf("Enter new date mounth is ");
	scanf("%u", &date.mm);
	datec = setMonth(datec, date.mm);
	date = uncompressDate(datec);
	printDate(date);
	printCompressedDate(datec);

	// Установка нового года

	printf("Enter new date year is ");
	scanf("%u", &date.yy);
	datec = setYear(datec, date.yy);
	date = uncompressDate(datec);
	printDate(date);
	printCompressedDate(datec);

	return 0;
}
