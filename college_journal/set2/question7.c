// Operations
// push, pop, peek, update, view array and exit;

#include <stdio.h>
#define MAX 10

typedef struct {
  int arr[MAX];
  int top;
} Stack;

int isEmpty(Stack* stack){
  if(stack -> top == -1) 
    return 1;
  else 
    return 0;
}

int isFull(Stack* stack) {
  if(stack -> top >= MAX) 
    return 1;
  else 
    return 0;
}


void push(Stack* stack, int value){
  if(isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }

  stack -> arr[++stack -> top] = value;
}

void pop(Stack* stack, int* output){
  if(isEmpty(stack)) {
    printf("Stack underflow\n");
    return;
  }

  *output = stack -> arr[stack -> top];
  stack -> arr[stack -> top] = 0;
  --(stack -> top);
}

void peek(Stack* stack){
  if(isEmpty(stack)) {
    printf("Stack underflow\n");
    return;
  }

  printf("Top element is: %d\n", stack->arr[stack->top]);

}

void update(Stack* stack, int pos, int value) {
  if(isEmpty(stack)) {
    printf("Stack underflow\n");
    return;
  }

  if(pos <= stack -> top) {
    stack -> arr[pos] = value;
  } else {
    printf("Invalid position\n");
  }
}


void viewArray(Stack* stack) {
  printf("[");
  for(int i=0; i<MAX-1; i++) {
    printf("%d, ", stack -> arr[i]);
  }
  printf("%d]\n", stack -> arr[MAX-1]);
}



int main() {
  Stack stack = { .arr = {0}, .top = -1};

  do {

    printf("Choose an option:\n");
    printf("1. Push\n");
    printf("2. Pop\n");
    printf("3. Peek\n");
    printf("4. Update\n");
    printf("5. View Array\n");
    printf("6. Exit\n");

    int choice, value, pos, poppedVal;
    printf("Your choice: ");
    scanf("%d", &choice);

    switch(choice) {
      case 1: 
        printf("Value to push: ");
        scanf("%d", &value);
        push(&stack, value);
        break;

      case 2:
        pop(&stack, &poppedVal);
        printf("Popped value is %d\n", poppedVal);
        break;

      case 3:
        peek(&stack);
        break;

      case 4:
        printf("Enter position: ");
        scanf("%d", &pos);

        printf("Value to update: ");
        scanf("%d", &value);
        update(&stack, pos, value);
        break;

      case 5:
        viewArray(&stack);
        break;

      case 6:
        goto exit;
        break;

      default:
        printf("Invalid choice\n");
    }

  } while(1);


  exit:
    printf("Successfully exited from the program\n");

  return 0;
}