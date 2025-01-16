#include <stdio.h>
#include "stack_functions.h"

void menu();

int main(){

    Stack stack1;
    int choice, n;

    // printf("Enter the length of the string: ");
    // scanf("%d", &n);

    char string[] = "(()())";

    // printf("\nEnter the string: ");
    // scanf("%s", string);

    for(int i = 0; i < 7; i++){

        if(string[i] == ')'){

            if(stack1.length == 0){

                printf("Invalid");
                break;
            }

            stack1.pop();
        }

        if(string[i] == '(')
            stack1.push(string[i]);
    }

    if(stack1.length == 0)
        printf("Valid");

    else
        printf("Invalid");
}