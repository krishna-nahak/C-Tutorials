#include <stdio.h>
#include "../extendedFn.c"

int main() {
  char * name;
  scanf("%s", name);
  // char month[];  not allowed, size is required
  // char month[10];
  // char weekday[] = "tuesday";
  println("%s", name);
  // println("%s", weekday);
  // println("%c", month[0]);
  return 0;
}