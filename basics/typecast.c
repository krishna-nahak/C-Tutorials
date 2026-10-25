#include <stdio.h>

int main() {
  // type conversion during a operation
  // must return a value of bigger type

  // int op int -> int (2b)
  // char op int -> int (2b)
  // int op float -> float (4b)

  // implicit and explicit conversion

  // implicit only allows small to big container
  // explicit forcefully convert big data into small container

  // int a =  1.999999;
  int a = (int) 1.999999;
  printf("%d", a);
  printf("\n");

  return 0;
}