# include <stdio.h>

struct Animal
{

    int rno;
    char name[50];
    int mark;

};

int main() {

    struct Animal student;

    printf("rno:\n");
    scanf("%d", &student.rno);
    

    return 0;
}