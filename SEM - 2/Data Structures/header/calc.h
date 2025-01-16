#include <stdio.h>

int number1, number2;

void set(){

    printf("Enter the number 1: ");
    scanf("%d", &number1);

    printf("\nEnter the number 2: ");
    scanf("%d", &number2);
}

int add(){

    return (number1 + number2);
}

int subtract(){

    return (number1 - number2);
}

int multiply(){

    return (number1 * number2);
}

float divide(){

    return ((float) number1 / (float) number2);
}