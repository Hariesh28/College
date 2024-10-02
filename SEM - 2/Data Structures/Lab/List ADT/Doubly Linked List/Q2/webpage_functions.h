#include <stdio.h>

class webpage{

    struct node{

        struct node *prev;
        int data;
        struct node *next;
    };

    struct node *head;
    struct node *current;

    public:
        webpage(){

             head = NULL;
             current = NULL;
        }

        void insert();
        void display();
        void front();
        void back();
};


// Inserts a web page into the list of nodes with random data
void webpage::insert(){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = rand();
    printf("Value: %d\n", new_node->data);
    new_node->next = NULL;

    if(current == NULL){

        new_node->prev = NULL;

        current = new_node;
        head = new_node;

        printf("Inserted Successfully");
    }

    else{

        struct node *temp1 = current;
        struct node *temp2 = (struct node *) malloc(sizeof(struct node));

        if(temp1->next){

            temp1 = temp1->next;

            while(temp1){

                temp2->next = temp1->next;
                free(temp1);
                temp1 = temp2->next;
            }
        }

        new_node->prev = current;
        current->next = new_node;
        current = new_node;

        printf("Inserted Successfully");
    }
}

// Displays the list
void webpage::display(){

    if(head == NULL){

        printf("Empty List");
    }

    else{
     
        struct node *temp = head;

        printf("Elements in the list are: ");
        while(temp){

            printf("%d ", temp->data);
            temp = temp->next;
        }
    }
}

// Goes a node front
void webpage::front(){

    if(current == NULL){

        if(head == NULL){

            printf("Can't move Front");
        }

        else{

            if(head){

                current = head;
                printf("Moved Front");
            }
        }
    }

    else{

        if(current->next == NULL){

            printf("Can't Move Front");
        }
        
        else{

            if(current->next){

                current = current->next;
                printf("Moved Front");
            }
        }
    }
}

// Goes back a node
void webpage::back(){

    if(current == NULL){

        printf("Can't move back");
    }

    else{

        if(current->prev != NULL){

            current = current->prev;
            printf("Moved Back");
        }

        else if(current->prev == NULL){

            current = NULL;
            printf("Moved Back");
        }
    }
}
