#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>


char ** parse_args( char * line ) {
  char ** ret = (char**) calloc(6,sizeof(char*));
  if (!ret) {
    printf("%s\n", strerror(errno));
  }
  int i = 0;
  while (line) {
    ret[i] = strsep(&line, " ");
    i ++;
  }
  return ret;
}

int main () {
  char line[100] = "ls -a -l";
  char ** args = parse_args(line);
  if (execvp(args[0], args) < 0) {
    printf("%s\n", strerror(errno));
  }
  return 0;
}
