#include<stdio.h>
#include<math.h>

typedef unsigned short datec_t;

typedef enum Month {
	JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG,
	SEP, OCT, NOV, DEC, MONTHS = 12
} Month;

typedef struct Date {
	int dd;
	Month mm;
	int yy;
} Date;

datec_t compressDate(Date d);

Date uncompressDate(datec_t dc);

datec_t setDay(datec_t dc, int newDay);

datec_t setMonth(datec_t dc, Month newMonth);

datec_t setYear(datec_t dc, int newYear);

void printDate(Date d);

void printCompressedDate(datec_t d);

datec_t compressDate(Date d) {
	datec_t res;
	res=d.yy;
	res += d.dd * pow(2, 7);
	res += d.mm * pow(2, 12);
	return res;
}

Date uncompressDate(datec_t dc) {
	Date res;
	res.yy = dc % int(pow(2, 7));
	dc /=(pow(2, 7));
	res.dd = dc % int(pow(2, 5));
	dc /= (pow(2, 5));
	res.mm = Month(dc);
	return res;
}

datec_t setDay(datec_t dc, int newDay) {
	Date d = uncompressDate(dc);
	d.dd = newDay;
	return compressDate(d);
}

datec_t setMonth(datec_t dc, Month newMonth) {
	Date d = uncompressDate(dc);
	d.mm = newMonth;
	return compressDate(d);
}

datec_t setYear(datec_t dc, int newYear) {
	Date d = uncompressDate(dc);
	d.yy = newYear;
	return compressDate(d);
}

void printDate(Date d) {
	printf("date is %u.%u.%u\n", d.dd, d.mm, d.yy);
	return;
}

void printCompressedDate(datec_t d) {
	printf("compressed date is %u\n", d);
	return;
}
