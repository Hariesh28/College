#include <stdio.h>
#include <stdlib.h>

class Stack{

    struct node{

        char data;
        struct node *next_node;
    };
    
    struct node *head;

    public:
        Stack(){

            head = NULL;
        }

        void push(char);
        int length();
        char pop();
        char peek();
        void display();
};

// Adds the data into the stack
void Stack::push(char data){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = data;
    new_node->next_node = head;
    head = new_node;
}

// Returns the length of the stack
int Stack::length(){

    int len = 0;
    struct node *temp = head;

    while(temp){

        len++;
        temp = temp->next_node;
    }

    return len;
}

// Deletes adn returns the top element
char Stack::pop(){

    if(head == NULL)
        return '_';

    struct node *temp = head;
    char result = temp->data;
    head = head->next_node;
    free(temp);

    return result;
}

// Display the stacks
void Stack::display(){

    struct node *temp = head;

    if(temp == NULL)
        printf("Empty List");

    else{

        while(temp){

            printf("%c ", temp->data);
            temp = temp->next_node;
        }
    }
}

//Returns the top element
char Stack::peek(){

    if(head == NULL)
        return '_';

    return head->data;
}