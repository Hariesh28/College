#include <stdio.h>
#include <string.h>

int main(){

    char string[100];

    printf("Enter String: ");
    scanf("%s", string);
    printf("Got string: %s\n", string);
    
    int open = 0;
    int close = 0;
    int opened = 0;
    int length = strlen(string);

    if(length != 0){

        if(string[0] != '(' || string[length - 1] != ')'){

            printf("Nope");
            printf("\nInvalid");
        }

        else{
            
            for(int i = 0; i < length; i++){

                if(string[i] == '('){
                    
                    opened++;
                    open++;
                }

                else if(string[i] == ')'){
                    
                    opened--;
                    close++;   
                }
            }

            printf("Open: %d\nClose: %d\nOpened: %d", open, close, opened);

            if(opened == 0)
                printf("\nValid");

            else
                printf("\nInvalid");
        }
    }

    return 0;
}