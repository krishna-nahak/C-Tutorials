#include <stdio.h>

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];
  int firstLargest = 0, secondLargest = 0;

  printf("\nEnter your elements: \n");
  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
    if(nums[i] > firstLargest) firstLargest = nums[i];
  }

  // find second largest
  for(int i=0; i<size-1; i++){
    if(nums[i] == firstLargest) continue;
    if(nums[i] > secondLargest) secondLargest = nums[i];

  }

  printf("\nSecond largest element is: %d\n", secondLargest);
  return 0;
}


/*
output
Enter number of elements: 5 
Enter your elements: 
1: 100
2: 99
3: 0
4: -1000
5: 23  
Second largest element is: 99
*/