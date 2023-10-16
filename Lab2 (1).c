#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main() {
  srandom(1);
  pid_t child_1 = fork();
  int rand_num = rand() % 30;
  wait(NULL);
  for (int i = 0; i < rand_num; i++){
    printf("Child Pid: %d is going to sleep!\n", getpid());
    sleep(rand() % 10);
    printf("Child Pid: %d is awake!\nWhere is my Parent: %d\n",getpid(),getppid());
  }
  printf("Child Pid: %d has completed.\n",getpid());
  exit(0);
  
  wait(NULL);
  pid_t child_2 = fork();
  if (child_2 == 0){
    for (int i = 0; i < rand_num; i++){
      printf("Child Pid: %d is going to sleep!\n", getpid());
      sleep(rand() % 10);
      printf("Child Pid: %d is awake!\nWhere is my Parent:     %d\n?",getpid(),getppid());
    }
    exit(0);
    printf("Child Pid: %d has completed\n",getpid());
  }else{
    printf("Fork failed.");
  }
}