#include <stdlib.h>
#include <stdio.h>

//forward declarations
int calculateWeekday(char* date);
char* mapWeekdayNumberToCanonicalName(int weekdayNumber);

int main(int argc, char* argv[]) {

	int weekday = calculateWeekday(argv[1]);

	printf("Weekday number is: %d\n", weekday);

	char* canonicalMonthName = mapWeekdayNumberToCanonicalName(weekday);
	
	printf("Weekday name   is: %s\n", canonicalMonthName);

	return 0;
}

int calculateWeekday(char* date) {
	
	int d; // day
	int m; // month
	int y; // year

	sscanf(date, "%02d/%02d/%04d", &d, &m, &y);

	y = (m == 1 || m==2 ) ? y-1 : y;

	int c = y /100; // century
	y = y % 100;

	if(m==1) m = 13; //since Roman times month were from March .. Feb (March was the first Month) 1..12
	if(m==2) m = 14;
	m -= 2;

	int weekday = (d + (13*m-1)/5 + y + y/4 + c/4 + 5*c) %7;

	return weekday;

}

char* mapWeekdayNumberToCanonicalName(int weekdayNumber) {

	switch(weekdayNumber) {
		case 0: return "Sunday";
		case 1: return "Monday";
		case 2: return "Tuesday";
		case 3: return "Wednesday";
		case 4: return "Thursday";
		case 5: return "Friday";
		case 6: return "Saturday";
	}
}
