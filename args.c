#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

char ** parse_args( char * line ) {
  char ** ret = (char**) calloc(6,sizeof(char*));
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
  execvp(args[0], args);
  return 0;
}
