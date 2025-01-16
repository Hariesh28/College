/*            BUBBLE SORT            */

#include <stdio.h>
#include <stdbool.h>

void sort(int*, int, bool);

int main(){

	int num_len, choice;
	
	printf("Enter the number of entries: ");
	scanf("%d", &num_len);
	
	int number_arr[num_len];
	
	for (int i = 0; i < num_len; i++){
	
		printf("\nEnter: ");
		scanf("%d", &number_arr[i]);
	}
	
	printf("\n1)Ascending\n2)Decending");
	printf("\nEnter: ");
	scanf("%d", &choice);
	
	switch (choice){
	
		case 1:
			sort(number_arr, num_len, true);

			for (int i = 0; i < num_len; i++)
				printf("%d ", number_arr[i]);

			break;
		
		case 2:
			sort(number_arr, num_len, false);

			for (int i = 0; i < num_len; i++)
				printf("%d ", number_arr[i]);
		
			break;
		
		default:
			printf("\nInvaild Choice");
			break;
	}
	
	printf("\n");

	return 0;
}

void sort(int *numbers, int len, bool ascending){
	
	int temp;
		
	if (ascending){
	
		for (int i = 0; i < len; i++){
			
			for(int j = i + 1; j < len; j++){
			
				if(numbers[j] < numbers[i]){
				
					// Swapping

					temp = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = temp;
				}
			}
		}
	}
			
	else{
		for (int i = 0; i < len; i++){
		
			for(int j = i + 1; j < len; j++){
		
				if(numbers[j] > numbers[i]){

					temp = numbers[i];
					numbers[i] = numbers[j];
					numbers[j] = temp;
				}
			}
		}
	}
}
