#include <stdio.h>

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];

  int posCount = 0, negCount = 0, zeroCount = 0;
  printf("\nEnter your elements: \n");

  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
    if(nums[i] == 0) zeroCount++;
    else (nums[i] > 0) 
      ? posCount++
      : negCount++;
  }

  printf("\n Negative Count -> %d\n Positive Count -> %d\n Zero Count -> %d\n", negCount, posCount, zeroCount);

  return 0;
}


/*
output
Enter number of elements: 4
Enter your elements: 
1: -1
2: -0
3: 23
4: 45
 Odd Count -> 3
 Even Count -> 1

*/