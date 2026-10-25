#include <stdio.h>

int main() {

  int age;
  char * name;
  scanf("%d", &age);

  while(age) {
    printf("age is %d", age);
    break;
  }

  printf("\n");

  do{
    printf("age is %d", age);
    break;
  } while(age);

  printf("\n");

  for(int i=0; i<3; i++) {
    printf("\n");
    printf("Countdown %d", i);
  }
  return 0;
}