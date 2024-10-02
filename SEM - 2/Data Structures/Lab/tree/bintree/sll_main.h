#include <stdio.h>
#include <stdlib.h>

void menu();

class SLL{

    struct stack_node{

        char data;
        struct stack_node *next_stack_node;
    };

    struct stack_node *head;

    public:
        SLL(){

            head = NULL;
        }

        int push(char);
        void pop();
        void peek();
        void display();
};

//Adds a element to the stack
int SLL::push(char car){

    struct stack_node *new_stack_node = (struct stack_node *) malloc(sizeof(struct stack_node));

    new_stack_node->data = car;
    new_stack_node->next_stack_node = head;
    head = new_stack_node;

    return 1;
}

// Deletes and prints the top element
void SLL::pop(){

    struct stack_node *temp = head;

    if(head){

        printf("Deleted Element is: %c", head->data);

        head = head->next_stack_node;
        free(temp);
    }

    else
        printf("Empty Stack");
}

// prints the top value of the list
void SLL::peek(){

    if(head)
        printf("Top element is: %c", head->data);
    
    else
        printf("Empty Stack");
}

//Displays the stack
void SLL::display(){

    if(head){
        
        struct stack_node *temp = head;
        
        printf("Elements in the stack are: ");
        while(temp){
            
            printf("%c ", temp->data);
            temp =temp->next_stack_node;
        }
    }

    else
        printf("Empty Stack");
}

void menu(){

    getchar();
    getchar();
    system("clear");

    printf("1) Push");
    printf("\n2) Pop");
    printf("\n3) Peek");
    printf("\n4) Display");
    printf("\n5) Exit\n");
}