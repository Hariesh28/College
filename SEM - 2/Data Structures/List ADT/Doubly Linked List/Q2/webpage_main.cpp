#include <stdio.h>
#include <stdlib.h>
#include "webpage_functions.h"

void menu();

int main(){

    webpage webpage1;
    int choice;
    
    while(1){

        menu();
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                webpage1.insert();
                break;

            case 2:
                webpage1.front();
                break;

            case 3:
                webpage1.back();
                break;

            case 4:
                webpage1.display();
                break;

            case 5:
                printf("Exited");
                return 0;
                
            default:
                printf("Invalid choice\n");
                break;
        }
    }

    return 0;
}

void menu(){

    getchar();
    getchar();
    system("cls");

    printf("1) New Webpage\n");
    printf("2) Front\n");
    printf("3) Back\n");
    printf("4) Display\n");
    printf("5) Exit\n");
}