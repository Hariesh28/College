#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void menu();

class hash{

    struct node{

        int data;
        struct node *next;
    };

    struct node *hash_table[SIZE];

    int find_index(int);

    public:
        hash(){

            for(int i = 0; i < SIZE; i++)
                hash_table[i] = NULL;
        }

        int insert(int);
        int remove(int);
        int search(int);
};

int main(){

    hash h1;
    int choice, number;

    while(true){

        menu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter a number: ");
                scanf("%d", &number);

                if(h1.insert(number))
                    printf("Inserted Successfully");

                else
                    printf("Cannot insert");

                break;

            case 2:
                printf("Enter a number: ");
                scanf("%d", &number);

                if(h1.remove(number))
                    printf("Deleted Successfully");

                else
                    printf("Cannot delete");

                break;

            case 3:
                printf("Enter a number: ");
                scanf("%d", &number);

                if(h1.search(number))
                    printf("Found !");

                else
                    printf("Not Found !");

                break;

            case 4:
                printf("Exited !");
                return 0;

            default:
                printf("Invalid Choice");
                break;
        }
    }

    return 0;
}


int hash::insert(int number){

    int index = find_index(number);    
    struct node *head = hash_table[index];

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    new_node->data = number;
    new_node->next = NULL;

    if(head == NULL){

        hash_table[index] = new_node;
        return 1;
    }

    else{

        while(head->next != NULL){

            if(head->data == number)
                return 0;

            head = head->next;
        }

        if(head->data == number)
            return 0;
        
        head->next = new_node;

        return 1;
    }
}

int hash::find_index(int number){

    int index = number % SIZE;

    return index;
}

int hash::remove(int number){

    int index = find_index(number);
    struct node *head = hash_table[index];
    struct node *previous = NULL;

    if(head == NULL)
        return 0;

    if(head->data == number){

        hash_table[index] = hash_table[index]->next;
        return 1;
    }

    while(head){

        if(head->data == number){

            previous->next = head->next;
            free(head);
            return 1;
        }

        previous = head;
        head = head->next;
    }

    return 0;
}

int hash::search(int number){

    int index = find_index(number);
    struct node *head = hash_table[index];

    if(head == NULL)
        return 0;

    if(head->data == number)
        return 1;

    while(head){

        if(head->data == number)
            return 1;

        head = head->next;
    }

    return 0;
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("cls");

    printf("1) Insert\n");
    printf("2) Delete\n");
    printf("3) Search\n");
    printf("4) Exit\n");

    printf("Enter: ");
}