#include <stdio.h>
#include <string.h>
#include "stack.h"

#define zero 48
#define nine 57


int main(){

    int precedence(char);
    Stack stack1;


    char string[] = "3+5-2*4+6/3-1";
    char array[strlen(string)];
    int array_top = -1;

    for(int i = 0; i < strlen(string); i++){
        
        if(string[i] >= zero && string[i] <= nine){

            printf("%c ", string[i]);
            array_top++;
            array[array_top] = string[i];
        }

        if(precedence(string[i]) != 0){

            
        }
    }
    printf("\n");
    for(int i = 0; i <= array_top; i++)
        printf("%c ", array[i]);

    return 0;
}

//Returns a number for a symbol
int precedence(char oper){

    if(oper == '+' || oper == '-')
        return 1;

    if(oper == '*' || oper == '/')
        return 2;

    return 0;       
}