#include <stdio.h>
#include <stdlib.h>

class LinkedList{

    struct node{

        struct node *next_node;
        int data;
    };

    struct node *head;

    struct node* gethead(){

        return head;
    }

    public:
        LinkedList(){

            head = NULL;
        }

        int insert(int);
        int merge(LinkedList, LinkedList);
        void display();
};

//Inserts the data in ascending Order
int LinkedList::insert(int number){

    struct node *new_node = (struct node*) malloc(sizeof(struct node));
    new_node->data = number;

    if(!head || head->data >= number){

        new_node->next_node = head;
        head = new_node;
        
        return 1;
    }

    else{

        struct node *temp = head;

        while(temp->next_node && temp->next_node->data < number){

            temp = temp->next_node;
        }

        new_node->next_node = temp->next_node;
        temp->next_node = new_node;

        return 1;
    }

    return 0;
}

// Merges two lists into the third
int LinkedList::merge(LinkedList list1, LinkedList list2){

    struct node *temp1 = list1.gethead();
    struct node *temp2 = list2.gethead();
    struct node *tail = head;

    if (!temp1 && !temp2)
        return 0;

    else{

        while(temp1 && temp2){

            struct node *new_node = (struct node *) malloc(sizeof(struct node));

            if(temp1->data < temp2->data){

                new_node->data = temp1->data;
                temp1 = temp1->next_node;
            }

            else{

                new_node->data = temp2->data;
                temp2 = temp2->next_node;
            }

            new_node->next_node = NULL;
    
            if(tail)
                tail->next_node = new_node;
    
            tail = new_node;

            if(!head)
                head = new_node;
        }

        while(temp1){

            struct node *new_node = (struct node *) malloc(sizeof(struct node));

            new_node->data = temp1->data;
            new_node->next_node = NULL;

            if(tail)
                tail->next_node = new_node;
    
            tail = new_node;

            if(!head)
                head = new_node;

            temp1 = temp1->next_node;
        }

        
        while(temp2){

            struct node *new_node = (struct node *) malloc(sizeof(struct node));

            new_node->data = temp2->data;
            new_node->next_node = NULL;

            if(tail) 
                tail->next_node = new_node;
    
            tail = new_node;
            
            if(!head)
                head = new_node;
            
            temp2 = temp2->next_node;
        }

        return 1;
    }
}

//Prints the data in the given list
void LinkedList::display(){

    if(!head)
        printf("Empty List");

    else{

        struct node *temp = head;

        printf("Elements in the list are: ");
        while(temp){

            printf("%d ", temp->data);
            temp = temp->next_node;
        }
    }
}