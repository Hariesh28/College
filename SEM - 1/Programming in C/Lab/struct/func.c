# include <stdio.h>

void mult(int* ptr, int elements){

    int *a;

    a = ptr;

    for(int i = 0; i < elements; i++){

        *ptr *= 5;
        ptr += 1;  // Size ??
    }

    for(int i = 0; i < elements; i++){

        printf("\n%d", *a);
        a += 1;
    }
}


void main(){

    int choice, numbers[100];
    int *p;

    printf("Enter the number of elements: ");
    scanf("%d", &choice);

    for(int i = 0; i < choice; i++){

        printf("\nEnter element %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    p = &numbers[0]; // p = numbers

    mult(p, choice);
}   