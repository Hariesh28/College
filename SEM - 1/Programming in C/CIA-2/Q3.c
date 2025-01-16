#include <stdio.h>

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int getDaysInMonth(int month, int year) {
    int daysInMonth[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    if (month == 2 && isLeapYear(year)) {
        return 29;
    }

    return daysInMonth[month];
}

void addDays(int *day, int *month, int *year, int daysToAdd) {
    while (daysToAdd > 0) {
        int daysInCurrentMonth = getDaysInMonth(*month, *year);
        
        if (daysToAdd <= (daysInCurrentMonth - *day)) {
            *day += daysToAdd;
            daysToAdd = 0; 
        } else {
            daysToAdd -= (daysInCurrentMonth - *day + 1);
            *day = 1;
            
            if (*month == 12) {
                *month = 1;
                *year += 1;
            } else {
                *month += 1;
            }
        }
    }
}

int main() {
    int day, month, year;

    printf("Enter date (DD MM YYYY): ");
    scanf("%d %d %d", &day, &month, &year);

    addDays(&day, &month, &year, 63);

    printf("Final date after adding 63 days: %02d %02d %d\n", day, month, year);

    return 0;
}
