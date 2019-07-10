#include <stdio.h>
#include <setjmp.h>

jmp_buf test1;

void tryjump() {
  longjmp(test1, 3);
}

void test() {
  int number = setjmp(test1);
  if (number==0) {
    printf ("test1: (%d) | %s\n", number, "setjmp() returned 0.");
    tryjump(); // CALL THIS TO GO TO ELSE CONDITION
  } else {        
    printf ("test1: (%d) | %s\n", number, "setjmp returned from a longjmp function call.");
  }
}

int main (void) {
  test();
}