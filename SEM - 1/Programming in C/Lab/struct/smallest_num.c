# include <stdio.h>

/* 

l = [3, 6, 2, 1, 9]

for _ in range(len(l)):
    for i in range(0, len(l) - 1):
        if l[i] > l[i + 1]:
            l[i], l[i + 1] = l[i + 1], l[i]

*/

int min(int arr[], int size){

    int *smallest = &arr[0];

    for(int i = 0; i < size; i++){

        if (*smallest > *(arr + i)){

            smallest = (arr + i);
        }
    }

    return *smallest;
}


void main(){

    int l[] = {2,5,9,1,4,6};

    printf("%d", min(l, 6));
}