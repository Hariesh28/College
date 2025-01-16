#include <stdio.h>

int search(int*, int, int);

int main(){

	int arr_len, search_num, count;

	printf("Enter the number of entries: ");
	scanf("%d", &arr_len);

	int arr[arr_len];
	
	for(int i = 0; i < arr_len; i++){

		printf("\nEnter: ");
		scanf("%d", &arr[i]);
	}

	printf("\nEnter number to search: ");
	scanf("%d", &search_num);

	count = search(arr, arr_len, search_num);

	if (count == 0)
		printf("\nNOT FOUND\n");
	
	else
		printf("\nFound %d times\n", count);
	
	return 0;
}

int search(int* num_arr, int len, int num){

	int count = 0;

	for (int i = 0; i < len; i++)	
		if (num == num_arr[i])
			count++;
	
	return count;
}
