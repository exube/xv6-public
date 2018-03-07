#include "types.h"
#include "user.h"
void of(int);
int main(void) {
  printf(1, "hi\n");
  of(1);
  exit(0);
}


void of(int a) {
  printf(1, "%x\n", &a);
  of(a+1);
}  
