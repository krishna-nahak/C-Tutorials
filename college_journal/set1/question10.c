#include <stdio.h>

void reversePrint(int* nums, int size) {

  printf("\nOriginal array: [");
  for(int i=0; i<size-1; i++) {
    printf("%d, ", nums[i]);
  }
  printf("%d ]\n", nums[size-1]);


  printf("Reversed array: [");
  for(int i=size-1; i>0; i--) {
    printf("%d, ", nums[i]);
  }
  printf("%d ]\n", nums[0]);


}

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];
  printf("\nEnter your elements: \n");
  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
  }

  reversePrint(nums, size);
  return 0;
}


/*
output
Enter number of elements: 4

Enter your elements: 
1: 23
2: 23
3: 09
4: 08

Original array: [23, 23, 9, 8 ]
Reversed array: [8, 9, 23, 23 ]
*/