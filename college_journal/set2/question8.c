#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
  int coef;
  int expo;
  struct Node *next;
} Node;

Node* createNode(int coef, int expo) {
  Node* newnode = (Node*) malloc(sizeof(Node));
  newnode->next = NULL;
  newnode->coef = coef;
  newnode->expo = expo;
  return newnode;
}

void display(Node* head) {
  if (head == NULL) {
    printf("0\n");
    return;
  }

  Node* temp = head;
  while (temp != NULL) {
    if (temp->expo == 0) {
      printf("%d", temp->coef);
    } else if (temp->expo == 1) {
      printf("%dx", temp->coef);
    } else {
      printf("%dx^%d", temp->coef, temp->expo);
    }

    printf(temp->next != NULL ? " + " : "\n");

    temp = temp->next;
  }
}

void append(Node** dest, Node* source) {
  Node* newnode = createNode(source->coef, source->expo);

  if (*dest == NULL) {
    *dest = newnode;
    return;
  }

  Node* temp = *dest;
  while (temp->next != NULL) {
    temp = temp->next;
  }

  temp->next = newnode;
}

Node* addPolynomial(Node* p1, Node* p2) {
  Node* result = NULL;

  while (p1 != NULL && p2 != NULL) {
    if (p1->expo > p2->expo) {
      append(&result, p1);
      p1 = p1->next;

    } else if (p1->expo < p2->expo) {
      append(&result, p2);
      p2 = p2->next;

    } else {
      int coef = p1->coef + p2->coef;
      int expo = p1->expo;
      
      if (coef != 0) {
        append(&result, &(Node){.coef = coef, .expo = expo});
      }

      p1 = p1->next;
      p2 = p2->next;
    }
  }

  while (p1 != NULL) {
    append(&result, p1);
    p1 = p1->next;
  }

  while (p2 != NULL) {
    append(&result, p2);
    p2 = p2->next;
  }

  return result;
}

int main() {
  Node *p1 = NULL, *p2 = NULL;

  // P1 = 5x^3 + 4x^2 + 2
  append(&p1, &(Node){.coef = 5, .expo = 3});
  append(&p1, &(Node){.coef = 4, .expo = 2});
  append(&p1, &(Node){.coef = 2, .expo = 0});

  // P2 = 3x^3 + 2x + 1
  append(&p2, &(Node){.coef = 3, .expo = 3});
  append(&p2, &(Node){.coef = 2, .expo = 1});
  append(&p2, &(Node){.coef = 1, .expo = 0});

  Node* sum = addPolynomial(p1, p2);
  display(sum);

  return 0;
}