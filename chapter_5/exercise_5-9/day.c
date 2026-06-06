#include <stdio.h>
static const short days1[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const short days2[] = {0, 31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
static const short * const daytab[2] = { days1, days2 };

int day_of_year(int year, int month, int day) {
    int i, leap;
    if (year < 1) {
        fprintf(stderr, "error: invalid year\n");
        return -1;
    }
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (month < 1 || month > 12 || day < 1 || day > *(daytab[leap] + month)) {
        fprintf(stderr, "error: invalid month or day\n");
        return -1;
    }
    for (i = 1; i < month; i++) {
        day += *(daytab[leap] + i);
    }
    return day;
}

void month_day(int year, int yearday, int *pmonth, int *pday) {
    int i, leap;
    if (year < 1) {
        fprintf(stderr, "error: invalid year\n");
        return;
    }
    leap = (year%4 == 0 && year%100 != 0) || year%400 == 0;
    if (yearday > 365+leap || yearday < 1) {
        fprintf(stderr, "error: invalid day of year\n");
        return;
    }
    for (i = 1; yearday > *(daytab[leap] + i); i++) {
        yearday -= *(daytab[leap] + i);
    }
    *pmonth = i;
    *pday = yearday;
}
