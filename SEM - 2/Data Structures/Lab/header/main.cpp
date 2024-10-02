#include <stdio.h>
#include "calc.h"

int main(){

    int choice;

    while(1){
        
        printf("\n1.Set");
        printf("\n2.Add");
        printf("\n3.Subtract");
        printf("\n4.Multiply");
        printf("\n5.Divide");
        printf("\n6.Exit\n");

        printf("Choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
            set();
            break;

            case 2:
            printf("\n%d", add());
            break;

            case 3:
            printf("\n%d", subtract());
            break;

            case 4:
            printf("\n%d", multiply());
            break;

            case 5:
            printf("\n%.4f", divide());
            break;

            case 6:
            printf("\nExited !!");
            return 0;

            default:
            printf("\nInvaild Number");
            break;
        }
    }

    return 0;
}