/*

A Program To Implement List ADT Using Singly Linked List Data Structure

*/

#include <stdio.h>
#include <stdlib.h>
#include "methods.h"


int main(){

    LinkedList list1, list2, list3;

    int number, choice;

    while(1){

        getchar();
        getchar();
        system("cls");

        printf("1) Insert list 1");
        printf("\n2) Insert list 2");
        printf("\n3) Display list 1");
        printf("\n4) Display list 2");
        printf("\n5) Display list 3");
        printf("\n6) Merge\n");

        printf("Enter: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the number: ");
                scanf("%d", &number);

                if(list1.insert(number))
                    printf("Inserted Successfully");

                else
                    printf("Error");

                 break;

            case 2:
                printf("Enter the number: ");
                scanf("%d", &number);

                if(list2.insert(number))
                    printf("Inserted Successfully");

                else
                    printf("Error");

                 break;

            case 3:
                list1.display();
                break;

            case 4:
                list2.display();
                break;
            
            case 5:
                list3.display();
                break;

            case 6:
                if(list3.merge(list1, list2)){

                    printf("Inserted Sucessfully");
                }
                    
                break;

            default:
                printf("Invaild Choice");
                break;
        }
    }

    return 0;
}