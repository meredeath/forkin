#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>
#include <fcntl.h>

int main(){
  int f = fork();
  if(f){
    f = fork();
  }
  if(!f){
    printf("My PID: %d\n",getpid());
    int r = open("/dev/random", O_RDONLY);
    unsigned int* t;
    read(r, t, 4);
    close(r);
    sleep((*t)%15 +5);
    printf("Child process completed\n");
    return (*t)%15 +5;
  }
  int status;
  int p = wait(&status);
  printf("Completed child: %d\n",p);
  printf("Time slept: %d\n", WEXITSTATUS(status));
  printf("Parent completed\n");
  return 0;
}
