#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  pid_t id = fork();
  
  if(id == 0)
  {
    while(1)
    {
      printf("子进程, pid：%d, ppid: %d, id: %d\n", getpid(), getppid(), id);
      sleep(1);
    }
  }
  else if(id > 0)
  {
    while(1)
    {
      printf("父进程, pid：%d, ppid: %d, id: %d\n", getpid(), getppid(), id);
      sleep(1);
    }
  }
  else
  {
  }

  return 0;
}
