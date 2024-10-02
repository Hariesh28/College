#include <stdio.h>
#include <stdlib.h>

int main(){

    int *sum, *value, *n;

    sum = (int *) malloc(sizeof(int));
    value = (int *) malloc(sizeof(int));
    n = (int *) malloc(sizeof(int));

    *sum = 0;

    printf("Enter the number of number: ");
    scanf("%d", n);

    while(*n != 0){

        printf("\nEnter the number: ");
        scanf("%d", value);

        *sum += *value;

        *n -= 1;
    }

    printf("\nSum: %d\n", *sum);

    free(sum);
    free(value);
    free(n);

    return 0;
}