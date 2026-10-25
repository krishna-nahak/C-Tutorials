#include <stdio.h>


void bubbleSort(int* arr, int size) {

  for(int i=0; i<size-1; i++) {

    for(int j=i+1; j<size; j++) {
      if(arr[i] > arr[j]) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
      }                          
    }
  }
}

int main() {

  int nums[] = {90, 2, 1, -2, 100};
  int size = sizeof(nums) / sizeof(nums[0]);

  bubbleSort(nums, size-1);
  for(int i=0; i<size; i++) {
    printf("%d -> ", nums[i]);
  }
  return 0;
}