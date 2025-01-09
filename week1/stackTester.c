// Character Stack ADO tester

#include <stdio.h>
#include "charStack.h"

#define STRLEN 7

int main(void) {
   char str[STRLEN] = "string";
   int i = 0;
   
   StackInit();
   while (str[i] != '\0') {
      StackPush(str[i]);
      i++;
   }
   while (!StackIsEmpty()) {
      char c = StackPop();
      putchar(c);
   }
   putchar('\n');
   return 0;
}