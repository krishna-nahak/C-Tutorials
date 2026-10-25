#include <stdio.h>
#define MAX_SIZE 100

typedef struct {
  int arr[MAX_SIZE];
  int top;
} Stack;

void initialize(Stack* stack) {
  stack -> top = -1;
}

int isEmpty(Stack* stack) {
  return stack -> top == -1;
}

int isFull(Stack* stack){
  return stack -> top >= MAX_SIZE;
}

void push(Stack* stack){
  if(isFull) {
    printf("Stack overflow\n");
    return;
  }
}

void pop(Stack* stack);
void peek(Stack* stack);
void print(Stack* stack);




int main() {



  return 0;
}