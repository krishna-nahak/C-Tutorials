#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAX 100

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
  if(stack -> top >= MAX-1) 
    return 1;
  else 
    return 0;
}

void push(Stack* stack, int token){
  if(isFull(stack)) {
    printf("Stack overflow\n");
    return;
  }

  stack -> arr[++stack -> top] = token;
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


int isOperator(char* token) {
  if(strcmp(token, "-") == 0 
    || strcmp(token, "+") == 0
    || strcmp(token, "*") == 0
    || strcmp(token, "/") == 0
    || strcmp(token, "^") == 0) {

      return 1;
  } else 
      return 0;
}

int main() {

  Stack stack = { .top = -1 };

  char* expression[] = {"2", "3", "1", "*", "+", "9", "-"};
  int size = sizeof(expression) / sizeof(expression[0]);


  int num1=0, num2=0, result;
  for(int i=0; i<size; i++) {

    if(isOperator(expression[i]) == 1) {
      pop(&stack, &num1);
      pop(&stack, &num2);
      result = num1 + num2;
      push(&stack, result);

    } else 
      push(&stack, atoi(expression[i]));
  }


  printf("Result is %d", result);
	return 0;
}