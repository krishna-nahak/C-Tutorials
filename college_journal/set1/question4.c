#include <stdio.h>


int main() {
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

  // find largest element
  int largest = 0;
  for(int i=0; i<size; i++) {
    if(nums[i] > largest){
      largest = nums[i];
    }
  }

  printf("\nLargest value is %d\n", largest);


  return 0;
}


/*
output
Enter number of elements: 3
Enter your elements: 
1: 23
2: 1000
3: -10000
Largest value is 1000
*/