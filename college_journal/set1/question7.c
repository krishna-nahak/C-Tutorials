#include <stdio.h>

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];

  int evenCount = 0, oddCount = 0;
  printf("\nEnter your elements: \n");

  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
    (nums[i] % 2 == 0) 
      ? evenCount++
      : oddCount++;
  }

  printf("\n Odd Count -> %d\n Even Count -> %d\n", oddCount, evenCount);

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