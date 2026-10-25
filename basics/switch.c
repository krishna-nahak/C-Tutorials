#include <stdio.h>
#include "../extendedFn.c"

// problem with switch case

int main() {

  int day;
  scanf("%d", &day);
  switch(day = 20) {
    case 20:
      println("We got 20 days");
    case 0:
      println("I am dooms day");
      break;
    default:
      println("I am nothing");
  }
  return 0;
}