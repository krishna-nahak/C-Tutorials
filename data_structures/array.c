#include <stdio.h>

int main() {
  int arr[5]; // no initialization, all elements initialized with some random value
  // int arr[5] = {1,2,3,4,5}; // complete initialization
  // int arr[5] = {0}; // initialize all elements with zero
  // int arr[5] = {1,2}; // partial initialization and rest elements will be zero
  // int arr[5] = {1,2, [3] = 34, [4] = 56}; // specific initialization

  for(int i=0; i<5; i++ ) {
    printf("arr[%d] = %d", i, arr[i]);
    printf("\n");
  }

  printf("Size of an array: %lu\n", sizeof(arr));

  return 0;
}