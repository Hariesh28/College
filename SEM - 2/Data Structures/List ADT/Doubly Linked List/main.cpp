/*

A Program To Implement List ADT Using Doubly Linked List

*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu();

class DoubleLinkedList{

    struct node{

        struct node *previous_node;
        int data;
        struct node *next_node;
    };

    struct node *head;
    int length = 0;

    public:
        DoubleLinkedList(){

            head = NULL;
        }

        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int, int);

        void delete_beginning();
        void delete_end();
        void delete_position(int);

        void search(int);
        void display();
        void display_reverse();
};

int main(){

    DoubleLinkedList list1;
    int number, position, choice;

    while(1){

        menu();

        printf("Enter: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter number: ");
                scanf("%d", &number);

                list1.insert_beginning(number);
                printf("Inserted Successfully");

                break;

            case 2:
                printf("Enter number: ");
                scanf("%d", &number);

                list1.insert_end(number);
                printf("Inserted Successfully");

                break;

            case 3:
                printf("Enter number: ");
                scanf("%d", &number);

                printf("Enter position: ");
                scanf("%d", &position);

                if(position < 0)
                    printf("Invalid Position");

                else{

                    list1.insert_position(number, position);
                    printf("Inserted Successfully");
                }

                break;

            case 4:
                list1.delete_beginning();
                break;

            case 5:
                list1.delete_end();
                break;

            case 6:
                printf("Enter position: ");
                scanf("%d", &position);

                if(position < 0)
                    printf("Invalid Position");

                else{

                    list1.delete_position(position);
                }

                break;

            case 7:
                printf("Enter number: ");
                scanf("%d", &number);

                list1.search(number);
                break;

            case 8:
                list1.display();
                break;

            case 9:
                list1.display_reverse();
                break;

            case 10:
                printf("Exited !\n");
                return 0;

            default:
                printf("Invalid Choice");
                break;
        }
    }

    return 0;
}

// Insert at the beginning
void DoubleLinkedList::insert_beginning(int number){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = number;
    new_node->previous_node = NULL;
    new_node->next_node = head;

    if(head)
        head->previous_node = new_node;

    head = new_node;
    length++;
}

// Insert at the end
void DoubleLinkedList::insert_end(int num){

    if(head == NULL)
        insert_beginning(num);

    else{

        struct node *temp = head;
        struct node *new_node = (struct node *) malloc(sizeof(struct node));

        new_node->data = num;
        new_node->next_node = NULL;

        while(temp->next_node){ // Last node

            temp = temp->next_node;
        }

        new_node->previous_node = temp;
        temp->next_node = new_node;
        length++;
    }
}

// Insert at a given position
void DoubleLinkedList::insert_position(int number, int position){

    if(head == NULL || position == 0)
        insert_beginning(number);

    else{

        int current_index = 0;
        struct node *new_node = (struct node *) malloc(sizeof(struct node));
        struct node *temp = head;

        new_node->data = number;

        while(temp->next_node && current_index < position - 1){ // Goes to the node before the specified index

            temp = temp->next_node;
        }

        new_node->previous_node = temp;
        new_node->next_node = temp->next_node;

        if(temp->next_node)
            temp->next_node->previous_node = new_node;

        temp->next_node = new_node;
        length++;
    }
}

// Delete at the beginning
void DoubleLinkedList::delete_beginning(){

    if(head == NULL)
        printf("Empty list");

    else if(head->next_node == NULL){ // Only One element is present in the list

        printf("Deleted ELement is: %d", head->data);

        free(head);

        head = NULL;
        length--;
    }

    else{

        printf("Deleted Element is %d", head->data);

        head = head->next_node;
        free(head->previous_node);
        head->previous_node = NULL;

        length--;
    }
}

// Delete at the end
void DoubleLinkedList::delete_end(){

    if(head == NULL)
        printf("Empty List");

    else{

        struct node *temp = head;

        while(temp->next_node){ // Last node

            temp = temp->next_node;
        }

        printf("Deleted Element is: %d", temp->data);
        length--;

        if(temp->previous_node){

            temp->previous_node->next_node = NULL;
            free(temp);
        }

        else{

            free(temp);
            head = NULL;
        }
    }
}

// Delete at a given position
void DoubleLinkedList::delete_position(int position){

    if(head == NULL)
        printf("Empty List");

    else if(head->next_node == NULL || position == 0)
        delete_beginning();

    else{

        int current_node_index = 0;
        struct node *temp = head;

        while(temp->next_node && current_node_index < position){ // Goes to the mentioned index or the last element

            temp = temp->next_node;
            current_node_index++;
        }

        printf("Deleted Element is: %d", temp->data);
        length--;

        temp->previous_node->next_node = temp->next_node;

        if(temp->next_node)
            temp->next_node->previous_node = temp->previous_node;

        free(temp);
    }
}

// Returns the index of the given element
void DoubleLinkedList::search(int search_number){

    if(head == NULL)
        printf("Empty List");

    else{

        bool flag = true;
        int index = 0;
        struct node *temp = head;

        while(temp){

            if(temp->data == search_number){

                printf("Element found at index: %d", index);
                flag = false;
                break;
            }

            temp = temp->next_node;
            index++;
        }

        if(flag)
            printf("Not Found");
    }
}

// Prints the list
void DoubleLinkedList::display(){

    if(head == NULL)
        printf("Empty List");

    else{

        struct node *temp = head;

        printf("Elements in the list are: ");
        while(temp){

            printf("%d ", temp->data);
            temp = temp->next_node;
        }

        printf("\nLength of the list is: %d", length);
    }
}

// Prints the list in reverse order
void DoubleLinkedList::display_reverse(){

    if(head == NULL)
        printf("Empty List");

    else{

        struct node *temp = head;

        while(temp->next_node){  // Goes to the last node

            temp = temp->next_node;
        }

        printf("Elements in the list are: ");
        while(temp){

            printf("%d ", temp->data);
            temp = temp->previous_node;
        }

        printf("\nLength of the list is: %d", length);
    }
}

// Basic menu
void menu(){

    getchar();
    getchar();
    system("cls");

    printf("1. Insert Beginning");
    printf("\n2. Insert End");
    printf("\n3. Insert Position");
    printf("\n4. Delete Beginning");
    printf("\n5. Delete End");
    printf("\n6. Delete Position");
    printf("\n7. Search");
    printf("\n8. Display");
    printf("\n9. Display Reverse");
    printf("\n10. Exit\n");
}
