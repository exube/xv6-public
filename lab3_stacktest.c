// Lab3 stack size test
//
// In this code, I try to write code that tries to
// grow the stack into the (currently imaginary) heap.
// This uses recursion and a large array to quickly 
// grow the stack. 
// The heap resides immediately above the code section,
// which is nearly at the bottom of the address space.
//
// This code executes for an estimated 30 seconds, growing
// the stack to address 0x72262310 before running out of 
// memory.  This is nowhere near the bottom of the 
// address space where the code is located.  
//
// By doing some calculations, I can see that the stack
// grew to about 232MB before it got killed.  By looking
// from the top of the user space (0x7FFFFFFF), we need 
// about 2GB of physical memory before we can consume 
// enough virtual memory to get the stack to the heap.
// Keep in mind that this 2GB of physical memory is for
// userspace only -- we're going to need about 250MB more
// for the kernel. 

#include "types.h"
#include "user.h"
void of(int);
int main(void) {
  printf(1, "hi\n");
  of(1);
  exit(0);
}


void of(int a) {
  __attribute__((unused)) char b[4096];
  b[0] = 0;
  printf(1, "%x\n", &a);
  of(a+1);
}  
