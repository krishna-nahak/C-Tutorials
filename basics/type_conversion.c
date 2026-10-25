#include <stdio.h>
#include <string.h>

int main() {

  // character -> digit

  // isDigit -> function
  // to check whether a character is between 0-9

  char* digit = "900";
  int isDigit = 1;
  for(int i=0; i<strlen(digit); i++) {
    int chCode = digit[i];
    if(!(chCode >= 48 && chCode < 58)) {
      isDigit = 0;
      break;
    }
  }

  printf("%d\n", isDigit);

  return 0;
}