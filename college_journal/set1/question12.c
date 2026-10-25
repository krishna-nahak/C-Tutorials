#include <stdio.h>

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];
  int firstSmallest = 0, secondSmallest = 0;

  printf("\nEnter your elements: \n");
  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
    if(nums[i] < firstSmallest) firstSmallest = nums[i];
  }

  // find second largest
  for(int i=0; i<size-1; i++){
    if(nums[i] == firstSmallest) continue;
    if(nums[i] < secondSmallest) secondSmallest = nums[i];

  }

  printf("\nSecond smallest element is: %d\n", secondSmallest);
  return 0;
}


/*
output
Enter number of elements: 4
Enter your elements: 
1: 23
2: -100
3: -999
4: 90
Second smallest element is: -100
*/