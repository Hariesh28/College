/*******************************************************************************

                        Experiment 3 - Structures & Unions

*******************************************************************************/
#include <stdio.h>
#include <string.h>
union Employee
{
  float salary;
  int id;
  char name[5];
};
struct Employee_s
{
  float salary;
  int id;
  char name[5];
};

int
main ()
{
  union Employee data1;
  struct Employee_s data2;
  char name[] = "Groot";
  data1.salary = 123.12;
  data2.salary = 124.12;
  printf ("Union  - %d,%f,%s\n", data1.id, data1.salary, data1.name);
  printf ("Struct - %d,%f,%s\n", data2.id, data2.salary, data2.name);
  strcpy (data1.name, name);
  strcpy (data2.name, name);
  printf ("Union  - %d,%f,%s\n", data1.id, data1.salary, data1.name);
  printf ("Struct - %d,%f,%s\n", data2.id, data2.salary, data2.name);
  data1.id = 12;
  data2.id = 12;
  printf ("Union  - %d,%f,%s\n", data1.id, data1.salary, data1.name);
  printf ("Struct - %d,%f,%s\n", data2.id, data2.salary, data2.name);

  printf ("Size of Union = %ld\n", sizeof (data1));
  printf ("Size of Struct = %ld\n", sizeof (data2));
  return 0;
}
