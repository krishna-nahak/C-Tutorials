#include <stdio.h>

//. perform insertion and deletion in an array

int currentIdx = -1;

void display(int* nums, int size) {
  if(currentIdx < 0) {
    printf("[ ]\n");
    return;
  }
  if(currentIdx < size) size = currentIdx;

  printf("[");
  for(int i=0; i<size; i++) {
    printf("%d, ", nums[i]);
  }
  printf("%d]\n", nums[size]);
}


int delete(int* nums, int pos, int size) {
  if (pos >= size || pos >= currentIdx) return 0;

  int i=0;
  for(i=pos; i<size-1; i++) {
    nums[i] = nums[i+1];
  }
  
  nums[i] = 0;
  currentIdx--;
  return 1;
}


int main() {

  int size;
  printf("Enter number of elements: ");
  scanf("%d", &size);

  int nums[size];
  int choice, pos, i = 0;

  do {

    printf("Choose an option: \n");
    printf("1. Insertion\n");
    printf("2. Deletion\n");
    printf("3. Display\n");
    printf("4. Exit\n");

    printf("Your choice : ");
    scanf("%d", &choice);

    switch(choice) {
      case 1:
        printf("Enter element: ");
        scanf("%d", &nums[i++]);
        currentIdx++;
        break;

      case 2:
        printf("Enter position: ");
        scanf("%d", &pos);
        printf(
          delete(nums, pos, size) == 1 
            ? "Successfully deleted\n" 
            : "Failed to delete\n");
        break;
      
      case 3:
        display(nums, size);
        break;

      case 4:
          goto exit;

      default:
        printf("Invalid choice\n");
    }

  } while(1);


  exit:
    printf("Successfully exited from the program\n");

  return 0;
}