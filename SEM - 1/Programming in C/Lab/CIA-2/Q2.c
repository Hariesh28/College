# include <stdio.h>
# define and &&

int calc_age(int, int, int);

struct Age {

    int date;
    int month;
    int year;
};

int main() {

    int age;
    struct Age a;

    printf("Date: ");
    scanf("%d", &a.date);

    printf("\nMonth: ");
    scanf("%d", &a.month);

    printf("\nYear: ");
    scanf("%d", &a.year);

    age = calc_age(a.date, a.month, a.year);

    if (age >= 18){

        printf("Greater");
    }

    else printf("Lesser");

}

int calc_age(int date, int month, int year) {

    int age;

    if (date < 18 and month < 11){

        age = 2022 - year;
    }

    else age = 2023 - year;

    printf("%d", age);

    return age;
}