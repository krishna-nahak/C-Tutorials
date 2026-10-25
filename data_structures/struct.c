#include <stdio.h>

// definition
struct student {
  int roll_no;
  char* name;
};


// self referential structure
typedef struct {
  int data;
  node* next;
} node;

int main() {

  // declaring
  struct student stud1 = {21, "Krishna"};

  struct student stud2 = stud1;
  printf("Name of student: %s\n", stud1.name);
  printf("Roll no of %s: %d\n", stud1.name, stud1.roll_no);
  printf("%ld", (long) &stud1);
  return 0;
}                               