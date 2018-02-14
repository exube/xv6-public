#include "types.h"
#include "user.h"

int main(void) {
  printf(1, "Hi! I'm main() and I will fork into 1 computationally-bound process with priority 1 and 1 I/O-bound process with priority 30.\n");

  int pid = fork();
  setpri(16);

  if (!pid) {
    printf(1, "I/O bound. Priority = %d. Enter 10 characters.\n", getpri(-1));
    char buf[11];
    read(0, buf, 10);
    buf[10] = 0;
    printf(1, "I/O bound. Priority = %d. You entered %s.  Ran for %d ticks\n", getpri(-1), buf, getticks());
  } else {
    printf(1, "Comp-bound.  Priority = %d. Running 8 billion nop's.\n", getpri(-1));
    for (int i = 0; i < 200000; i++) 
      for (int j = 0; j < 40000; j++)
        asm("nop");
    printf(1, "Comp-bound.  Priority = %d. Ran for %d ticks\n", getpri(-1), getticks());
  }
  
  exit(0);
}
  
