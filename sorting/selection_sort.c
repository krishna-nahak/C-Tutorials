#include <stdio.h>

void selectionSort(int arr[], int size) {

  int min_idx = -1;
  for(int i=0; i<size-1; i++){
    min_idx = i;

    for(int j=i+1; j<size; j++) {
      int key = arr[j];
      if(key < arr[i]) {
        min_idx = j;
      }
    }

    int temp = arr[i];
    arr[i] = arr[min_idx];
    arr[min_idx] = temp;
  }
}

int main() {

  int nums[5] = {1, 9, 5, 4, 3};

  selectionSort(nums, 5);
  for(int i=0; i<5; i++) {
    printf("%d -> ", nums[i]);
  }

  return 0;
}