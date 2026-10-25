#include <stdio.h>
#include <stdlib.h>

struct Node {
  int data;
  struct Node* next;
};

struct Node* head;

struct Node* createNode(int data) {
  struct Node* newNode = (struct Node*) malloc(sizeof (struct Node));
  newNode -> data = data;
  newNode -> next = NULL;
  return newNode;
}

void insertAtFirst(int data){
  struct Node* newNode = createNode(data);
  newNode -> next = head;
  head = newNode;
}

void insertAtEnd(int data){
  if(head == NULL) {
    head = createNode(data);
    return;
  }

  struct Node* temp = head;
  while(temp -> next != NULL) {
    temp = temp -> next;
  }

  struct Node* newNode = createNode(data);
  temp -> next = newNode;
}

void insertAtPosition(int data, int pos){
  if(pos == 0) {
    insertAtFirst(data);
    return;
  }

  struct Node* temp = head;
  for( int i=0; i<(pos-1); i++) {
    temp = temp -> next;
  }

  if(temp == NULL) {
    printf("Index out of bound\n");
    return;
  }

  struct Node* newNode = createNode(data);
  newNode -> next = temp -> next;
  temp -> next = newNode;
}

void deleteAtFirst(){
  if(head == NULL) {
    printf("List is underflow\n");
    return;
  }

  struct Node* temp = head;
  head = head -> next;
  free(temp);
}

void deleteAtEnd(){
  if(head == NULL) {
    printf("List is underflow\n");
    return;
  }

  struct Node* temp = head;
  while((temp -> next != NULL) 
    && (temp -> next -> next != NULL)) {

    temp = temp -> next;
  }

  free(temp -> next);
  temp -> next = NULL;
}

void deleteAtPosition(int pos){
  if(pos == 0) {
    deleteAtFirst();
    return;
  }

  struct Node* temp = head;
  for( int i=0; i< pos-1; i++) {
    temp = temp -> next;
  }

  if(temp == NULL || temp -> next == NULL){
    printf("Index out of bound\n");
    return;
  }

  struct Node* next = temp -> next -> next;
  free(temp -> next);
  temp -> next = next;
}

void print(){
  if(head == NULL){
    printf("List is underflow\n");
    return;
  }

  struct Node* temp = head;
  while(temp != NULL){
    printf("%d -> ", temp -> data);
    temp = temp -> next;
  }

  printf(" NULL\n");
}


int main(){

  int choice, data, pos;

  printf("Welcome to LinkedList \n");
  printf("Choose a option from given below:\n");
  printf("1. Insert at First\n");
  printf("2. Insert at Position\n");
  printf("3. Insert at End\n");
  printf("4. Delete at First\n");
  printf("5. Delete at End\n");
  printf("6. Delete at Position\n");
  printf("7. Print\n");
  printf("8. Exit\n");


  do {
    printf("Enter your choice: ");
    scanf("%d", &choice);
    printf("\n");

    switch(choice) {
      case 1:
        printf("Enter a number: ");
        scanf("%d", &data);
        printf("\n");
        insertAtFirst(data);
        break;

      case 2:
        printf("Enter a number: ");
        scanf("%d", &data);
        printf("\n");

        printf("Enter position: ");
        scanf("%d", &pos);
        printf("\n");

        insertAtPosition(data, pos);
        break;

      case 3:
        printf("Enter a number: ");
        scanf("%d", &data);
        printf("\n");
        insertAtEnd(data);
        break;

      case 4:
        deleteAtFirst();
        break;

      case 5:
        deleteAtEnd();
        break;
      
      case 6:
        printf("Enter position: ");
        scanf("%d", &pos);
        printf("\n");

        deleteAtPosition(pos);
        break;

      case 7:
        print();
        break;

      case 8:
        goto outro;
        break;

      default: 
        printf("Invalid choice\n");
    }
  } while(choice != 8);

  outro:
  printf("Program Ends Here\n");
  return 0;
}