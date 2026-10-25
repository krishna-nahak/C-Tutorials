#include <stdio.h>

int main() {

  int age, scannedResult;
  scannedResult = scanf("%d", &age);
  if(age > 10) {
    printf("We got the age %d", age);
    printf("\n");
    printf("Buy your Giant Wheel Ticket");
  } else {
    printf("Your age is not qualified to enter Giant Wheel");
  }

  printf("\n");
  printf("Scanned Result is %d", scannedResult);
  return 0;
}