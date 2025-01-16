#include <stdio.h>
#include <stdlib.h>

void menu();

class SLL{

    struct node{

        char data;
        struct node *next_node;
    };

    struct node *head;

    public:
        SLL(){

            head = NULL;
        }

        int push(char);
        void pop();
        void peek();
        void display();
};

int main(){

    SLL stack;
    int choice;
    char charr;

    while(1){

        menu();

        printf("Enter: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the charr: ");
                scanf(" %c", &charr);

                if(stack.push(charr))
                    printf("Added Sucessfully");

                else
                    printf("Failed to add");

                break;

            case 2:
                stack.pop();
                break;

            case 3:
                stack.peek();
                break;

            case 4:
                stack.display();
                break;

            case 5:
                printf("Exited !");
                return 0;

            default:
                printf("Invaild Choice");
                break;
        }
    }

    return 0;
}

//Adds a element to the stack
int SLL::push(char car){

    struct node *new_node = (struct node *) malloc(sizeof(struct node));

    new_node->data = car;
    new_node->next_node = head;
    head = new_node;

    return 1;
}

// Deletes and prints the top element
void SLL::pop(){

    struct node *temp = head;

    if(head){

        printf("Deleted Element is: %c", head->data);

        head = head->next_node;
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
        
        struct node *temp = head;
        
        printf("Elements in the stack are: ");
        while(temp){
            
            printf("%c ", temp->data);
            temp =temp->next_node;
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