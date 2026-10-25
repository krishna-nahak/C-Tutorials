#include <stdio.h>
#include <math.h>

int checkPrime(int num) {

  if(num == 0) return 0;
  if(num == 1) return 1;
  
  for(int i=2; i<=sqrt(num); i++) {
    if(num % i == 0) return 0;
  }

  return 1;
}

int main(){
  int size, sum=0;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];

  int primeCount = 0;
  printf("\nEnter your elements: \n");

  for(int i=0; i<size; i++) {
    printf("%d: ", i+1);
    scanf("%d", &nums[i]);
    if(checkPrime(nums[i])) primeCount++;
  }

  printf("\n Prime number Count -> %d\n", primeCount);

  return 0;
}


/*
output
Enter number of elements: 5
Enter your elements: 
1: -1
2: 2
3: 1
4: 0
5: 4
 Prime number Count -> 3
*/