#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void menu();

class stack{

    char array[SIZE];
    int cur;

    public:
        stack(){

            cur = -1;
        }

        int push(char);
        void pop();
        void peek();
        void display();
};

int main(){

    stack stack;
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

//Adds the element to the stack
int stack::push(char charr){

    if(cur == SIZE - 1){

        return 0;
    }

    else if(cur == -1){

        array[0] = charr;
        cur = 0;

        return 1;
    }

    else{

        for(int i = cur; i >= 0; i--){

            array[i+1] = array[i];
        }

        cur++;
        array[0] = charr;
        return 1;
    }
}

//deletes and prints the top element
void stack::pop(){

    if(cur == -1)
        printf("Empty stack\n");
    
    else{

        printf("Deleted Element is: %c", array[0]);

        for(int i = 0; i < cur; i++){

            array[i] = array[i+1];
        }

        cur--;
    }
}

// Prints the top element
void stack::peek(){

    if(cur == -1)
        printf("Empty stack\n");

    else
        printf("Top element is: %c", array[0]);
}

// prints the stack
void stack::display(){

    if(cur == -1){

        printf("Empty stack\n");
    }

    else{

        printf("Elements in the stack are: ");

        for(int i = 0; i <= cur; i++){

            printf("%c ", array[i]);
        }
    }
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("clear");

    printf("1) Push");
    printf("\n2) Pop");
    printf("\n3) Peek");
    printf("\n4) Display");
    printf("\n5) Exit\n");
}
