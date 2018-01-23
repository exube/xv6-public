#include "types.h"
#include "user.h"

int
main(int argc, char *argv[]) {
  int status = 1;
  int childid = fork();
  if (childid == 0) { // child
    exit(42);
  } else if (childid > 0) { //parent
    int asdf = waitpid(childid, &status, 0);
    printf(0, "child id %d exited with status %d\n", asdf, status);
  }
  exit(0);
}
