/*
A. Write a separate C++ menu-driven program to implement Priority Queue ADT using a max heap. Maintain proper boundary conditions and follow good coding practices. The Priority Queue ADT has the following operations,

1. Insert
2. Delete
3. Display
4. Search
5. Sort (Heap Sort) 
6. Exit

What is the time complexity of each of the operations?
*/



#include <stdio.h>
using namespace std;
#include <stdlib.h>
#include <queue>
#define SIZE 100

void menu();

class heap{

    int array[SIZE];
    int cursor;

    public:
        heap(){

            cursor = -1;
        }

    int insert(int num);
    void heapify();
    void display();
    int del();
    void sort(queue <int> q1);
    void displayq(queue <int> q1);
    int search(int num);
};

int main(){

    queue <int> q1;
    heap h1;

    int choice;
    int number;

    while(1){

        menu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the number: ");
                scanf("%d", &number);

                if(h1.insert(number))
                    printf("Inserted Successfully");

                else
                    printf("Can not insert");

                break;

            case 2:
                if(h1.del())
                    printf("Deleted Successfully");

                else
                    printf("Can not delete");

                break;

            case 3:
                h1.display();
                break;

            case 4:
                printf("Enter the number to seach: ");
                scanf("%d", &number);

                if(h1.search(number))
                    printf("Number found at %d", h1.search(number));

                else
                    printf("Number not found");

                break;
            
            case 5:
                h1.sort(q1);
                break;
            
            case 6:
                printf("Exited !");
                return 0;

            default:
                printf("Invalid Choice");
                break;
        }
    }

    return 0;
}

//Push into heap
// O(log n)
int heap::insert(int number){

    if(cursor == SIZE - 1)
        return 0;

    else if(cursor == -1){

        array[0] = number;
        cursor++;
        
        return 1;
    }

    else{

        cursor++;
        array[cursor] = number;
        heapify();

        return 1;
    }
}

// Heapify
// O(log n)
void heap::heapify(){

    int i = cursor;

    while(i > 0){

        int parent = (i-1)/2;

        if(array[i] > array[parent]){

            int temp = array[i];
            array[i] = array[parent];
            array[parent] = temp;
        }

        i--;
    }
}

// Displays the heap
// O(n)
void heap::display(){

    if(cursor == -1)
        printf("Emtpy heap !");

    else{

        for(int i = 0; i <= cursor; i++)
            printf("%d ", array[i]);
    }
}

// Delete
// O(log n)
int heap::del(){

    if(cursor == -1)
        return '\0';

    else{

        int temp = array[0];
        array[0] = array[cursor];
        array[cursor] = temp;

        heapify();

        return temp;
    }
}

// Search
// O(n)
int heap::search(int number){

    for(int i = 0; i <= cursor; i++)
        
        if(number == array[i])
            return i + 1;
    
    return 0;
}

// Sort in Descending order
// O(n log n)
void heap::sort(queue <int> q1){

    while(cursor != 1)
        q1.push(del());

    displayq(q1);
}

void heap::displayq(queue <int> q1){

    queue <int> q2 = q1;

    while(!q2.empty()){

        printf("%d ", q2.front());
        q2.pop();
    }
}

void menu(){

    printf("\n");
    getchar();
    getchar();
    system("cls");

    printf("1. Insert\n");
    printf("2. Delete\n");
    printf("3. Display\n");
    printf("4. Search\n");
    printf("5. Sort (Heap Sort) \n");
    printf("6. Exit\n");

    printf("Enter: ");
}