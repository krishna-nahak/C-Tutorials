#include <stdio.h>

int main(){
  int size;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];

  printf("\nEnter your elements: \n");
  for(int i=0; i<size; i++) {
    printf("\n%d: ", i+1);
    scanf("%d", &nums[i]);
  }

  printf("\nYour elements: ");
  printf("[");
  for(int i=0; i<size-1; i++) {
    printf("%d, ", nums[i]);
  }
  printf("%d", nums[size-1]);
  printf("]\n");

  return 0;
}