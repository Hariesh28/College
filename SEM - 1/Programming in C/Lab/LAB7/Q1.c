#include <stdio.h>

int
sum_n_cubes (int n)
{
// Your CODE goes HERE

int ans;

if (n == 0) return 0;
else return ((n*n*n) + sum_n_cubes(n-1));

// Till HERE
}

int
main ()
{
  int num;
  printf ("Enter n - ");
  scanf ("%d", &num);
  int rec_result = sum_n_cubes (num);
  // Update the formula here
  int formula_result;
  formula_result = ((num * (num + 1))/2) * ((num * (num + 1))/2);
  printf ("\nSum of cubes till %d is %d (recursion)", num, rec_result);
  printf ("\nSum of cubes till %d is %d (formula)", num, formula_result);
  return 0;
}