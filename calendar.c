#include <stdlib.h>
#include <stdio.h>

int calculateWeekday(char* date);

int main(int argc, char* argv[]) {


	calculateWeekday(argv[1]);

	return 0;

}

int calculateWeekday(char* date) {
	
	int d; // day
	int m; // month
	int y; // year

	sscanf(date, "%02d/%02d/%04d", &d, &m, &y);

	y = (m == 1 || m==2 ) ? --y : y;

	int c = y /100; // century
	y = y % 100;

	if(m==1) m = 13;
	if(m==2) m = 14;
	m -= 2;

	int weekday = (d + (13*m-1)/5 + y + y/4 + c/4 + 5*c) %7;

	printf("Weekday is: %d\n", weekday);

	return 0;
}




