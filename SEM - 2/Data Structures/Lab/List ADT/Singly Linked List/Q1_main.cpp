/*

A Program To Implement List ADT Using Singly Linked List Data Structure

*/


#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void menu();

class LinkedList{

    struct node{

        int data;
        struct node *next_node;
    };

    struct node *head;

    public:
        LinkedList(){

            head = NULL;
        }

        void insert_beginning(int);
        void insert_end(int);
        void insert_position(int, int);

        void delete_beginning();
        void delete_end();
        void delete_postion(int);
        
        void search(int);

        void display();
        void display_reverse();

        void reverse_link();
        int length();
};


int main(){

    int choice, num, pos;

    LinkedList list1;

    while(1){

        menu();

        printf("Enter: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the number: ");
                scanf("%d", &num);

                list1.insert_beginning(num);
                printf("Inserted Sucessfully");
                break;

            case 2:
                printf("Enter the number: ");
                scanf("%d", &num);

                list1.insert_end(num);
                printf("Inserted Sucessfully");
                break;

            case 3:
                printf("Enter the number: ");
                scanf("%d", &num);

                printf("Enter the postion: ");
                scanf("%d", &pos);

                if(pos < 0)
                    printf("Invaild Position");
                
                else{
                    list1.insert_position(num, pos);
                    printf("Inserted Sucessfully");
                }
                break;
            
            case 4:
                list1.delete_beginning();
                break;

            case 5:
                list1.delete_end();
                break;

            case 6:
                printf("Enter the position: ");
                scanf("%d", &pos);

                if(pos < 0){

                    printf("Invaild Position");
                }

                else{

                    list1.delete_postion(pos);
                    break;
                }
                break;

            case 7:
                printf("Enter the number: ");
                scanf("%d", &num);

                list1.search(num);
                break;

            case 8:
                list1.display();
                break;

            case 9:
                list1.display_reverse();
                break;

            case 10:
                list1.reverse_link();
                break;

            case 11:
                printf("Length of the list is: %d", list1.length());
                break;

            case 12:
                printf("\nExited !");
                return 0;

            default:
                printf("\nInvaild Choice");
                break;
        }
    }

    return 0;
}

// Inserts the number to the beginning of the list
void LinkedList::insert_beginning(int number){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = number;
    new_node->next_node = head; // Will be = NULL or = the address of the next node
    head = new_node;
}

// Inserts the number to the end of the list
void LinkedList::insert_end(int number){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    struct node *temp = head;

    if(temp == NULL){

        insert_beginning(number);
    }

    else{
        new_node->data = number;
        new_node->next_node = NULL;

        while(temp->next_node){   // Goes to the last node

            temp = temp->next_node;
        }

        temp->next_node = new_node;
    }
}


// Inserts the number to the given postion in the list
void LinkedList::insert_position(int number, int position){

    int count = 0;
    struct node *new_node = (struct node *) malloc(sizeof(struct node));
    struct node *temp = head;

    new_node->data = number;

    if(temp == NULL || position == 0){  // At position = 0, we do the same thing as insertion at the beginning

        new_node->next_node = head;  // = temp;
        head = new_node;    
    }

    else{

        while(temp->next_node != NULL && count < position - 1){  // Goes to the node before specified position

            temp = temp->next_node;
            count++;
        }

        new_node->next_node = temp->next_node;
        temp->next_node = new_node;
    }
}

// Deletes and prints the first element
void LinkedList::delete_beginning(){

    struct node *temp;

    temp = head;

    if(temp == NULL){

        printf("Empty List");
    }

    else{

        printf("Deleted Element is: %d", temp->data);
        head = temp->next_node;
        free(temp);
    }
}

// Deletes and prints the last element
void LinkedList::delete_end(){

    struct node *temp;

    temp = head;

    if(temp == NULL){

        printf("Empty List");
    }

    else if(temp->next_node == NULL){ // One Element

        printf("Deleted Element is: %d", temp->data);
        head = NULL;
        free(temp);
    }

    else{

        while(temp->next_node->next_node){  // Last before node

            temp = temp->next_node;
        }
        
        printf("Deleted Element is: %d", temp->next_node->data);

        free(temp->next_node);
        temp->next_node = NULL;
    }
}

// Deletes and Prints the element at the given position
void LinkedList::delete_postion(int pos){

    if(!head)
        printf("Empty list");

    else if(head->next_node == NULL || pos == 0)
        delete_beginning();

    else{

        int count = 0;
        struct node *temp2;
        struct node *temp = head;

        while(temp->next_node && count < pos - 1){

            temp = temp->next_node;
            count++;
        }

        if(temp->next_node){
            printf("Deleted Element is : %d", temp->next_node->data);
            temp2 = temp->next_node->next_node;
            free(temp->next_node);
            temp->next_node = temp2;
        }

        else
            delete_end();
    }
}

// prints the index of the given element
void LinkedList::search(int num){

    if(!head)
        printf("Empty List");
    
    else{

        bool flag = true;
        int index = 0;
        struct node *temp = head;
        
        while(temp){

            if(temp->data == num){
                
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

// Prints the elements of the list
void LinkedList::display(){

    struct node *current_node;

    current_node = head;

    if(current_node == NULL){

        printf("Empty list");
    }

    else{
        printf("Elements in the list are: ");

        while(current_node){  // != NULL

            printf("%d ", current_node->data);
            current_node = current_node->next_node;
        }
    }
}

// Prints the elements of the list in reverse order
void LinkedList::display_reverse(){

    struct node *current_node;
    int len = length();
    int arr[len];
    int index = 0;

    current_node = head;

    if(current_node == NULL){

        printf("Empty List");
    }

    else{
        printf("Elements in reverse order is: ");

        while(current_node){

            arr[index] = current_node->data;
            current_node = current_node->next_node;
            index++;
        }

        for(int i = length() - 1; i >= 0; i--){

            printf("%d ", arr[i]);
        }
    }
}

// Reverses the link
void LinkedList::reverse_link(){

    struct node *previous = NULL;
    struct node *next = NULL;

    if(!head)
        printf("Empty List");

    else{

        while(head){

            next = head->next_node;
            head->next_node = previous;
            previous = head;
            head = next;
        }

        head = previous;
        printf("Reversed Successfully");
    }
}

// Returns the length of the link
int LinkedList::length(){

    struct node *current_node;
    int len = 0;

    current_node = head;

    if(current_node == NULL){

        return len;
    }

    else{

        while(current_node){

            len++;
            current_node = current_node->next_node;
        }

        return len;
    }
}

void menu(){

    getchar();
    getchar();
    system("cls");

    printf("1) Insert Beginning");
    printf("\n2) Insert End");
    printf("\n3) Insert Position");
    printf("\n4) Delete Beginning");
    printf("\n5) Delete End");
    printf("\n6) Delete Position");
    printf("\n7) Search");
    printf("\n8) Display");
    printf("\n9) Display Reverse");
    printf("\n10) Reverse Link");
    printf("\n11) Length");
    printf("\n12) Exit\n");
}