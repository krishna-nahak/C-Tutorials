#include <stdio.h>


void sort_array(int* nums, int size);
int linear_search(int* nums, int size, int target){
  for( int i=0; i<size; i++ ) {
    if(target == nums[i]) return i;
  }

  return -1;
}

int binary_search(int* nums, int size, int target) {
  int mid, i = 0, j = size-1;
  sort_array(nums, size);
  
  while(i<=j) {
    mid = (i+j)/2;
    if(nums[mid] == target) 
      return mid;
    else if(nums[mid] < target) 
      j = mid-1;
    else 
      i = mid+1;
  }

  return -1;
}


void sort_array(int* nums, int size) {
  for(int i=0; i<size-1; i++) {
    for(int j=i+1; j<size; j++) {
      if(nums[i] > nums[j]) {
        int temp = nums[j];
        nums[j] = nums[i];
        nums[i] = temp;
      }
    }
  }
}

int main() {

  int nums[5] = {20, 1, 40, -2, 1000};

  int target, choice, idx = -1;
  printf("Enter search key: ");
  scanf("%d", &target);

  printf("Choose a searching technique from options given below\n");
  printf("1. Binary search.\n");
  printf("2. Lineary search.\n");
  printf("Your choice (1/2): ");
  scanf("%d", &choice);

  switch(choice) {
    case 1:
      idx = binary_search(nums, 5, target);
      break;

    case 2:
      idx = linear_search(nums, 5, target);
      break;

    default:
      printf("Invalid Choice\n");
  }

  printf( 
        idx == -1 
          ? "Target not found\n" 
          : "Found in index %d\n", idx 
      );

  return 0;
}