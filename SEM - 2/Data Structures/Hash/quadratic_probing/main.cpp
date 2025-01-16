#include <stdio.h>
#include <stdlib.h>
#define SIZE 10

void menu();

class hash{

    int hash_table[SIZE];

    int find_index(int);

    public:
        hash(){

            for(int i = 0; i < SIZE; i++)
                hash_table[i] = 0;
        }

        int insert(int);
        int remove(int);
        int search(int);
        void display();
};

int main(){

    hash h1;
    int choice, number;

    while(1){

        menu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter a number: ");
                scanf("%d", &number);

                if(h1.insert(number))
                    printf("Inserted Successfully");

                else
                    printf("Can't Insert !");

                break;

            case 4:
                printf("Elements in the hash tables are: ");
                h1.display();

                break;

            case 5:
                printf("Exited !");
                return 0;

            default:
                printf("Invalid Choice");
        }
    }

    return 0;
}

// Inserts a number into the hash table
int hash::insert(int number){

    int index = find_index(number);

    if(number == 0 || number == -1 || hash_table[index] == number)
        return 0;

    int i = 1;

    while(hash_table[index] != 0){ // If hash_table is full, infinite loop else, time complexity wtf ?
        // printf("%d ", index);
        if(hash_table[index] == number)
            return 0;

        // if(hash_table[index] == 0){
        
        //     hash_table[index] = number;
        //     return 1;
        // }
        
        index = find_index(i*i + index);
        i++;
    }

    hash_table[index] = number;

    return 1;
}

// Displays the hash table
void hash::display(){

    for(int i = 0; i < SIZE; i++)
        printf("%d ", hash_table[i]);
}

// Gets the index for the number
int hash::find_index(int number){
    
    int value = number % SIZE;

    if(value < 0)
        return (value + SIZE);

    return value;
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("cls");

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Search\n");
    printf("4. Display\n");
    printf("5. Exit\n");

    printf("Enter: ");
}