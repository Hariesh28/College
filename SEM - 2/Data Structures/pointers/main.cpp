#include <stdio.h>
#include <stdlib.h>

int main(){

	int *sum,*n,*value;

	n = (int *)malloc(sizeof(int));
	sum = (int *)malloc(sizeof(int));
	value = (int *)malloc(sizeof(int));

	*sum = 0;

	printf("\n Enter the value of n : ");
	scanf("%d", n);

	printf("Enter the integers : ");

	while(*n != 0){

		scanf("%d", value);
		*sum += *value;
		*n -= 1;
	}

	printf("\nSum is : %d\n", *sum);
	return 0;
}