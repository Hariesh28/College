#include <stdio.h>
#include <stdlib.h>
#include <queue>
#define SIZE 5 + 1

using namespace std;

void menu();

class graph{

    int adjacency_matrix[SIZE][SIZE];

    int current;

    public:
        graph(){

            for(int i = 0; i < SIZE; i++)
                for(int j = 0; j < SIZE; j++)
                    adjacency_matrix[i][j] = 0;
            
            current = 0;
        }

        int insert(int, int);
        int remove(int);
        int search(int);
        void display();
        void bfs();
};

int main(){

    graph g1;
    int choice;
    int vector1, vector2;
    int v;

    while(1){
        
        menu();
        scanf("%d", &choice);

        switch(choice){

            case 1:
                printf("Enter the vector 1: ");
                scanf("%d", &vector1);

                printf("Enter the vector 2: ");
                scanf("%d", &vector2);

                if(g1.insert(vector1, vector2))
                    printf("Inserted Successfully");

                else
                    printf("Failed to insert");

                break;

            case 2:
                printf("Enter the vector: ");
                scanf("%d", &v);

                if(g1.remove(v))
                    printf("Deleted Successfully");

                else
                    printf("Can't Delete");

                break;
                
            case 3:
                printf("Enter the vector: ");
                scanf("%d", &v);

                if(g1.search(v))
                    printf("Found !");
                
                else
                    printf("Not Found !");

                break;

            case 4:
                printf("Elements in the matrix are: \n");
                g1.display();
                break;

            case 5:
                printf("Elements in bfs are: \n");
                g1.bfs();
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

// Inserts two vectors into the graph
int graph::insert(int vector_1, int vector_2){

    int pos_vector_1 = 0;
    int pos_vector_2 = 0;

    for(int i = 1; i <= current; i++){

        if(adjacency_matrix[0][i] == vector_1)
            pos_vector_1 = i;

        if(adjacency_matrix[0][i] == vector_2)
            pos_vector_2 = i;
    }

    if(pos_vector_1 != 0 && pos_vector_2 != 0){

        adjacency_matrix[pos_vector_1][pos_vector_2] = 1;
        adjacency_matrix[pos_vector_2][pos_vector_1] = 1;

        return 1;
    }

    if(pos_vector_1 != 0 && pos_vector_2 == 0){
        
        if(current + 1 >= SIZE)
            return 0;

        current++;

        adjacency_matrix[0][current] = vector_2;
        adjacency_matrix[current][0] = vector_2;
    
        adjacency_matrix[current][pos_vector_1] = 1;
        adjacency_matrix[pos_vector_1][current] = 1;

        return 1;
    }

    if(pos_vector_1 == 0 && pos_vector_2 != 0){

        if(current + 1 >= SIZE)
            return 0;

        current++;

        adjacency_matrix[0][current] = vector_1;
        adjacency_matrix[current][0] = vector_1;
    
        adjacency_matrix[current][pos_vector_2] = 1;
        adjacency_matrix[pos_vector_2][current] = 1;

        return 1;
    }

    else{

        if(vector_1 != vector_2){
            
            if(current + 2 >= SIZE)
                return 0;

            adjacency_matrix[0][current + 1] = vector_1;
            adjacency_matrix[current + 1][0] = vector_1;

            adjacency_matrix[0][current + 2] = vector_2;
            adjacency_matrix[current + 2][0] = vector_2;

            adjacency_matrix[current + 1][current + 2] = 1;
            adjacency_matrix[current + 2][current + 1] = 1;

            current += 2;

            return 1;
        }

        else{

            if(current + 1 >= SIZE)
                return 0;

            adjacency_matrix[0][current + 1] = vector_1;
            adjacency_matrix[current + 1][0] = vector_1;
            
            adjacency_matrix[current + 1][current + 1] = 1;

            current++;

            return 1;
        }
    }
}

// Removes the given vector from the graph
int graph::remove(int vector){

    int pos_vector = 0;
    for(int i = 1; i <= current; i++){

        if(adjacency_matrix[0][i] == vector)
            pos_vector = i;
    }

    if(pos_vector == 0)
        return 0;

    for(int i = pos_vector; i < current; i++){
        for(int j = 0; j <= current; j++){

            adjacency_matrix[i][j] = adjacency_matrix[i + 1][j];
        }
    }

    for(int i = 0; i <= current; i++){
        for(int j = pos_vector; j < current; j++){

            adjacency_matrix[i][j] = adjacency_matrix[i][j + 1];
        }
    }

    current--;
    return 1;
}

// Search for a vector
int graph::search(int vector){

    for(int i = 0; i <= current; i++)
        for(int j = 0; j <= current; j++)
            if(adjacency_matrix[i][j] == vector)
                return 1;

    return 0;
}

// Prints the elements in the graph
void graph::display(){

    if(current == 0)
        printf("Empty graph");

    else{
        for(int i = 0; i <= current; i++){

            for(int j = 0; j <= current; j++){
                
                if(i == 0 && j == 0)
                    printf("X ");

                else
                    printf("%d ", adjacency_matrix[i][j]);
            }

            printf("\n");
        }
    }
}

void graph::bfs(){

    queue<int> q;
    int visited[SIZE] = {0};
    int cur = -1;

    if(current == 0)
        printf("Empty Graph");

    else{

        int start_vector = adjacency_matrix[0][1];
        q.push(start_vector);

        while(!q.empty()){

            int data = q.front();
            q.pop();
            // printf("%d ", data);

            int flag = 0;

            for(int i = 0; i <= cur; i++){

                if(visited[i] == data){

                    flag = 1;
                    break;
                }
            }

            if(flag == 0)
                printf("%d ", data);

            // for(int i = 0; i <= current; i++){
                    
            //     if(adjacency_matrix[i][0] == data){

            //         for(int j = 1; j <= current; j++){

            //             if(adjacency_matrix[i][j] == 1){
                            
            //                 data = adjacency_matrix[0][j];
            //                 q.push(data);
            //             }
            //         }
            //     }
            // }

            int pos = 0;
            for(int i = 1; i <= current; i++){

                if(adjacency_matrix[i][0] == data)
                    pos = i;
                    break;
            }

            if(pos != 0){

                for(int i = 1; i <= current; i++){

                    if(adjacency_matrix[pos][i] == 1){
                        
                        int adjacent_vertex = adjacency_matrix[0][i];
                        q.push(adjacent_vertex);
                    }
                }
            }
        }

        // for(int i = 0; i <= cur; i++)
        //     printf("%d ", visited[i]);
    }
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
    printf("5. BFS\n");
    printf("6. Exit\n");

    printf("Enter: ");
}