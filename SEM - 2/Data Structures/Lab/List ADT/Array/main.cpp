#include <stdio.h>
#include <stdlib.h>

#define SIZE 5

void menu();

class List{

    int array[SIZE];
    int cur;

    public:
        List(){

            cur = -1;
        }

        int insert_beginning(int);
        void insert_postion(int, int);
        int insert_end(int);
        int delete_beginning();
        int delete_postion(int);
        int delete_end();
        int search(int);
        void display();
};

int main(){

    List list1;
    int choice, num, pos, result;

    while(1){

        menu();

        printf("\nEnter: ");
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the number to add: ");
                scanf("%d", &num);

                if(list1.insert_beginning(num)){

                    printf("Added Sucessfully\n");
                }

                else{

                    printf("Failed to insert. The list is full\n");
                }

                break;

            case 2:
                printf("Enter the number to add: ");
                scanf("%d", &num);

                printf("\nEnter the postion: ");
                scanf("%d", &pos);

                list1.insert_postion(num, pos);
                
                break;

            case 3:
                printf("Enter the number to add: ");
                scanf("%d", &num);

                if(list1.insert_end(num)){

                    printf("Added Sucessfully\n");
                }

                else{

                    printf("Faild to insert. The list is full\n");
                }

                break;

            case 4:
                result = list1.delete_beginning();
                
                if(result){

                    printf("Sucessfully Deleted element: %d", result);
                }

                break;

            case 5:
                printf("\nEnter the postion: ");
                scanf("%d", &pos);

                result = list1.delete_postion(pos);

                if(result){

                    printf("Sucessfully Deleted element: %d", result);
                }
                
                break;

            case 6:
                result = list1.delete_end();

                if(result){

                    printf("Sucessfully Deleted element: %d", result);
                }

                break;

            case 7:
                printf("\nEnter the number to search: ");
                scanf("%d", &num);

                result = list1.search(num);

                if(result == -1){

                    printf("Empty list\n");
                }

                else if(result == -2){

                    printf("%d not found in list\n", num);
                }

                else{

                    printf("Found %d at index %d\n", num, result);
                }

                break;

            case 8:
                list1.display();
                break;

            case 9:
                printf("Exited !\n");
                return 0;

            default:
                printf("Please enter a vaild operation\n");
                break;
        }
    }

    return 0;
}

int List::insert_beginning(int number){

    if(cur == SIZE - 1){

        return 0;
    }

    else if(cur == -1){

        array[0] = number;
        cur = 0;

        return 1;
    }

    else{

        for(int i = cur; i >= 0; i--){

            array[i+1] = array[i];
        }

        cur++;
        array[0] = number;
        return 1;
    }
}

void List::insert_postion(int number, int postion){

    if (cur == SIZE - 1){

        printf("Faild to insert. The list is full\n");
    }

    else if(postion > cur + 1 || postion < -1){

        printf("Invaild postion\n");
    }

    else{

        for(int i = cur; i >= postion; i--){

            array[i+1] = array[i];
        }

        cur++;
        array[postion] = number;

        printf("Added Sucessfully\n");
    }
}

int List::insert_end(int number){

    if(cur == SIZE - 1){

        return 0;
    }

    else{

        array[cur + 1] = number;
        cur++;

        return 1;
    }
}

int List::delete_beginning(){

    if(cur == -1){

        printf("Empty List\n");
        return 0;
    }

    else{

        int result = array[0];

        for(int i = 0; i < cur; i++){

            array[i] = array[i+1];
        }

        cur--;
        return result;
    }
}

int List::delete_postion(int postion){

    if(cur == -1){

        printf("Empty List\n");
        return 0;
    }

    else if(postion > cur || postion < 0){

        printf("Invaid Position");
        return 0;
    }

    else{
        
        int result = array[postion];

        for(int i = postion; i < cur; i++){

            array[i] = array[i+1];
        }

        cur--;
        return result;
    }
}

int List::delete_end(){

    if(cur == -1){

        printf("Empty List\n");
        return 0;
    }

    else{

        int result = array[cur];
        cur--;
        return result;
    }
}

int List::search(int number){

    if(cur == -1){

        return -1;
    }

    else{

        for(int i = 0; i <= cur; i++){

            if(array[i] == number){
                
                return i;
            }
        }

        return -2;
    }
}

void List::display(){

    if(cur == -1){

        printf("Empty list\n");
    }

    else{

        printf("Elements in the list are: ");

        for(int i = 0; i <= cur; i++){

            printf("%d ", array[i]);
        }
    }
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("cls");

    printf("1) Insert at the beginning");
    printf("\n2) Insert at a postion");
    printf("\n3) Insert at the end");
    printf("\n4) Delete at beginning");
    printf("\n5) Delete at a postion");
    printf("\n6) Delete at end");
    printf("\n7) Search a element");
    printf("\n8) Display");
    printf("\n9) Exit");
}

// Hariesh R (AIDS - A) -> 23110344