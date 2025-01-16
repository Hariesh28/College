# include <stdio.h>

struct Students{

    char name[256];
    int rno;
    int marks[5];

} student[256];


struct Teachers {
    
    char name[256];
    int empno;
    char subject[256];

} teacher[256];


int main() {

    // Get Details Of Students

    int noOfStudents;

    printf("Enter the number of students: ");
    scanf("%d", &noOfStudents);

    for(int i = 0; i < noOfStudents; i++){

        printf("\nEnter the details of student %d.", i+1);

        printf("\nName: ");
        scanf("%s", student[i].name);

        printf("\nrno: ");
        scanf("%d", &student[i].rno);

        for (int j = 0; j < 5; j++){

            printf("\nEnter the mark of subject %d: ", j+1);
            scanf("%d", &student[i].marks[j]);
        }
    }

    // Get Details of Teachers

    int noOfTeachers;

    printf("\nEnter the number of teachers: ");
    scanf("%d", &noOfTeachers);

    for (int i = 0; i < noOfTeachers; i++){

        printf("\nEnter the details of teacher %d.", i+1);
        
        printf("\nName: ");
        scanf("%s", teacher[i].name);

        printf("\nEmp no: ");
        scanf("%d", &teacher[i].empno);

        printf("\nSubject: ");
        scanf("%s", teacher[i].subject);
    }

    // Print the details of students

    for (int i = 0; i < noOfStudents; i++){

        printf("\nDetails of student %d: ", i+1);

        printf("\nName: %s", student[i].name);
        printf("\nRoll no: %d", student[i].rno);
        
        for (int j = 0; j < 5; j++)
        printf("\nMark of Subject %d: %d", j+1, student[i].marks[j]);
    }

    // Print the details of teacher

    for (int i = 0; i < noOfTeachers; i++){

        printf("\nDetails of teacher %d: ", i+1);

        printf("\nName: %s", teacher[i].name);
        printf("\nRoll no: %d", teacher[i].empno);
        printf("\nSubject: %s", teacher[i].subject);        
    }
}