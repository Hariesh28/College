#include <stdio.h>
#include <time.h>
#define and &&
#define or ||
struct DateDay{

    int date, month, year;
    char day[15];
};
typedef struct DateDay dob;

dob today = {28, 11, 2023};
int monthlengths[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int isLeapYear(int year){

    if ((year % 4 == 0) and (year % 100!= 0) or (year % 400 == 0)) return 1;
    else return 0;
}   


int noOfDays(dob date){

    int days = 0, spare = 0;

    for(int year = date.year; year < today.year - 1; year++){

        if (isLeapYear(year) == 1) days += 366;
        else days += 365;
    }

    for(int i = 1; i < date.month; i++) spare += monthlengths[i];

    spare += date.date;

    if (isLeapYear(today.year-1) == 0) days += (366 - spare);
    else days += (365 - spare);

    for(int i = 1; i < today.month; i++) days += monthlengths[i];
    days += today.date;

    return days - 1; // Excludes current date
}


int main(){

    dob birthdate;
    birthdate.date = 28;
    birthdate.month = 6;
    birthdate.year = 2006;

    int days, rem;

    days = noOfDays(birthdate);
    rem = days % 7;

    switch (rem){

        case 0:
        printf("\nTuesday\n");
        break;

        case 1:
        printf("\nMonday\n");
        break;

        case 2:
        printf("\nSunday\n");
        break;

        case 3:
        printf("\nSaturday\n");
        break;

        case 4:
        printf("\nFriday\n");
        break;

        case 5:
        printf("\nThursday\n");
        break;

        case 6:
        printf("\nWednesday\n");
        break;
    }

    return 0;
}