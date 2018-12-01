#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
  printf("Hello from all threads\n");
  pid_t pid;
  if (pid = fork() < 0)
  {
    printf("Failed to fork\n");
    exit(1);
  }
  else if (pid == 0)
  {
    excuteChildProcess();
    exit(2);
  }
  else
  {
    executeParentProcess();
    int stat;
    wait(&status);

  }

  return 0;
}
