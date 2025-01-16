/*******************************************************************************

                        Experiment 2 - Structures 

*******************************************************************************/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <conio.h>

// Structure to store the data
struct Employee
{
  int id;
  char name[25];
  struct Personal
  {
    int age;
    char gender;
  } personal_data;
  struct Professional
  {
    int date_of_joining;
    char city[25];
    int experience;
  } prof_data;
};

typedef struct Employee empData;

void
print_chennaites (empData *empdata, int emp_count)
{
  int count = 0;
  while (count++ < emp_count)
    {
      
// Print the name of the employee and their age whose working location is CHENNAI
// YOUR CODE GOES HERE The below is just a format think and type your own logic

printf("(%d)", count);
printf("");// Name
printf("");// Age
// TILL HERE
      empdata++;
      printf ("\n");
    }
}

float
average_age (empData *empdata, int emp_count)
{
  float avg = 0.0;
  int count = 0;
  while (count++ < emp_count)
    {
// Compute the average age of employees
// YOUR CODE GOES HERE



// TILL HERE
      empdata++;
    }
  return avg;
}

int
main ()
{
  empData database[50];
  empData *dataptr;
  int emp_count = 0;
  scanf ("%d", &emp_count);
  dataptr = &database[0];

  int count = 0;
  while (count++ < emp_count)
    {
// Code to take input from emp.db sample on how to take input is in file input_sample.c 
// YOUR CODE GOES HERE


// TILL HERE
    }
  printf ("People working at CHENNAI Office\n");
  print_chennaites (dataptr, emp_count);
  printf ("Average age of workers is %f\n", average_age (dataptr, emp_count));
  return 0;
}
