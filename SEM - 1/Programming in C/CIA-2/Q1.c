# include <stdio.h>
# define and &&


int calc_greater(int date1, int month1, int year1 ,int date2, int month2, int year2) {

    if (year1 > year2) return 1;
    else if((year1 == year2) and month1 > month2) return 1;
    else if ((year1 == year2) and (month1 == month2) and (date1 > date2)) return 1;
    else return 2;

}

int isLeapYear(int year) {
    if ((year % 4 == 0 && year % 100 != 0) || (year % 400 == 0)) {
        return 1;
    } else {
        return 0;
    }
}

int main() {

    int date1, month1, year1 ,date2, month2, year2;
    int greater;
    
    printf("Date 1 details: ");
    printf("\nDate: ");
    scanf("%d", &date1);
    printf("\nMonth: ");
    scanf("%d", &month1);
    printf("\nYear: ");
    scanf("%d", &year1);

    printf("\n\nDate 2 details: ");
    printf("\nDate: ");
    scanf("%d", &date2);
    printf("\nMonth: ");
    scanf("%d", &month1);
    printf("\nYear: ");
    scanf("%d", &month2);

    greater = calc_greater(date1, month1, year1 ,date2, month2, year2);

    if (greater == 1){ 

        for(int i = year1; i > year2; year1--){

            if(isLeapYear(i) == 1){int feb = 29;}
            else {int feb = 28;}

        }    
    }

    return 0;
}