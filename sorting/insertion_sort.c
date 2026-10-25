#include <stdio.h>


void insertionSort(int* arr, int size){

  for(int i=1; i<size; i++) {
    int key = arr[i];
    int j = i-1;

    while(j>=0 && arr[j] > key ) {
      arr[j+1] = arr[j];
      j--;
    }

    arr[j+1] = key;
  }
}

int main() {

  int nums[5] = {1, 9, 5, 4, 3};

  insertionSort(nums, 5);
  for(int i=0; i<5; i++) {
    printf("%d -> ", nums[i]);
  }

  return 0;
}