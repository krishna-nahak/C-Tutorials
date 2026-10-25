#include <stdio.h>


int main() {
  int nums[5] = {23, 34, 54, -1, 90};
  int size = sizeof(nums)/sizeof(nums[0]);

  printf("Original array: [");
  for(int i=0; i<size-1; i++) {
    printf("%d, ", nums[i]);
  }
  printf("%d ]\n", nums[size-1]);

  // rotating array once
  int temp;
  for(int i=1; i<size; i++) {
    temp = nums[i-1];
    nums[i-1] = nums[i];
    nums[i] = temp;
  }


  printf("Rotated array: [");
  for(int i=0; i<size-1; i++) {
    printf("%d, ", nums[i]);
  }
  printf("%d ]\n", nums[size-1]);

  return 0;
}