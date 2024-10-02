# include <stdio.h>

int* mult(int arr[], int len){

    int *ptr;

    for(int i = 0; i < len; i++){

        arr[i] *= 5;
    }

    ptr = &arr[0];

    return ptr;
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

    p = mult(numbers, choice);

    for(int i = 0; i < choice; i++){
    printf("\n%d", &p);
    p += 1;
    }
}