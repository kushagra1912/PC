#include <stdio.h>
#include <string.h>
#include <wait.h>
#include <unistd.h>
#include <stdlib.h>

#define BUFSIZE 200
#define ARGVSIZE 40
#define DELIM "\n\t\r "

int main(int argc, char **argv){
  int i, n;
  char buf[BUFSIZE+1];
  char *clargs[ARGVSIZE];
  int returnval;

  for( ; ; ){
    n = 1;
    write(STDOUT_FILENO, "Shell> ", 7);
    read(STDOUT_FILENO, buf, BUFSIZE);
    if(!strcmp(buf, "exit\n"))
      exit(0);
    clargs[0] = strtok(buf, DELIM);

    while((clargs[n] = strtok(NULL, DELIM)) != NULL)
      n++;

    clargs[n] = NULL;

    switch(fork()){
      case 0:
        if((execvp(clargs[0], &clargs[0])) < 0){
          printf("%s: command not found\n", clargs[0]);
          exit(200);
        }
      default:
        wait(&returnval);
        printf("Exit Status of command: %d\n", WEXITSTATUS(returnval));
        for(int i = 0; i < n; i++)
          clargs[i] = "\0";
        for(int i = 0; i < BUFSIZE + 1; i++)
          buf[i] = '\0';
        
    }
  }
}