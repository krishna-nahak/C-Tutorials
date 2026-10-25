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

  // find smallest element
  int minValue = 0;
  for(int i=0; i<size; i++) {
    if(nums[i] < minValue){
      minValue = nums[i];
    }
  }

  printf("\nSmallest value is %d\n", minValue);


  return 0;
}


/*
output
Enter number of elements: 5
Enter your elements: 
1: 23
2: 09
3: -100
4: 90
5: 0
Smallest value is -100
*/