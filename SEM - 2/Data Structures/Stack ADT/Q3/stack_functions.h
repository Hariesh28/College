#include <stdlib.h>

class Stack{

    struct node{

        char data;
        struct node *next_node;
    };

    struct node *head;

    public:

        int length;
    
        Stack(){

            head = NULL;
            length = 0;
        }

        void push(char);
        void pop();
};

//Adds a char to the stack
void Stack::push(char charr){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = charr;
    new_node->next_node = NULL;

    head = new_node;
    length++;
}

//Deletes the top element
void Stack::pop(){

    struct node *temp = head;
    head = head->next_node;
    free(temp);
}