#include <stdio.h>

void sort(int*, int);
int binarySearch(int*, int, int);

int main(){

    int num_len, result, num_search;

    printf("Enter the number of entries: ");
    scanf("%d", &num_len);

    int arr[num_len];

    for (int i = 0; i < num_len; i++){

        printf("\nEnter: ");
        scanf("%d", &arr[i]);
    }

    printf("\nEnter the number to be searched: ");
    scanf("%d", &num_search);

    sort(arr, num_len);

    result = binarySearch(arr, num_len, num_search);

    if (result == -1)
        printf("\nNUMBER NOT FOUND !\n");
    
    else
        printf("\nRequried value is: %d\n", result);

    return 0;
}


void sort(int *num_array, int length){

    int temp;

    for (int i = 0; i < length; i++){

        for (int j = i + 1; j < length; j++){

            if (num_array[i] > num_array[j]){

                // Swapping

                temp = num_array[i];
                num_array[i] = num_array[j];
                num_array[j] = temp;
            }
        }
    }
}


int binarySearch(int *number_array, int length, int search_number){
    
    int low = 0;
    int high = length - 1;  // Index of last element
    int mid = (low + high) / 2;
    
    while (low <= high){

        if (number_array[mid] == search_number){

            return (mid + 1);   // Requried value as per question
        }

        else if (number_array[mid] > search_number){

            high = mid - 1;   // Select the lower half
            mid = (low + high) / 2; // Update the mid value
        }

        else if (number_array[mid] < search_number){

            low = mid + 1;  // Select the upper half
            mid = (low + high) / 2;
        }
    }

    return -1;  // Default return when no element is found
}
