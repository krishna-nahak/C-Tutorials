#include <stdio.h>

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];

  printf("\nEnter your elements: \n");
  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
    sum += nums[i];
  }

  printf("\nSum of all elements: %d\n", sum);

  return 0;
}