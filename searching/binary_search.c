#include <stdio.h>


void sortArray(int* arr, int size) {
  // bubble sort
  for( int i=0; i<size-1; i++) {
    for( int j=1; j<size; j++) {
      if(arr[j-1] > arr[j]){
        int temp = arr[j-1];
        arr[j-1] = arr[j];
        arr[j] = temp;
      }
    }
  }
}

// using loop
int binarySearch(int* arr, int size, int target){

  int result = -1;
  int mid, ub = size-1, lb = 0;
  mid = (ub + lb) / 2;

  sortArray(arr, size);

  for( int i=0; i<size; i++ ){
    printf("%d -- ", arr[i]);
  }

  while (ub >= lb) {
    mid = (ub + lb) / 2;
    if(arr[mid] == target){
      result = mid;
      break;
    } else if(target < arr[mid]){
      ub = mid-1;
    } else {
      lb = mid+1;
    }
  }

  return result;
}

// binary search
int recursiveSearch(int* arr, int ub, int lb, int target) {
  if(ub < lb) {
    return -1;
  }

  int mid = (ub+lb) / 2;
  if(arr[mid] == target) return mid;

  if(target < arr[mid]) {
    return recursiveSearch(arr, mid-1, lb, target);
  } else {
    return recursiveSearch(arr, ub, mid+1, target);
  }

}

int main() {

  int nums[6] = {90, 3, 5, -7, 9, 12};
  int target;

  printf("Enter target: ");
  scanf("%d", &target);
  printf("\n");

  int size = sizeof(nums)/ sizeof(nums[0]);
  sortArray(nums, size);
  printf("index of %d is %d\n", target, recursiveSearch(nums, size-1, 0, target));

  return 0;
}