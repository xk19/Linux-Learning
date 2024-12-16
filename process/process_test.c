#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
  pid_t id = fork();
  
  if(id == 0)
  {
    int cnt = 5;
    while(cnt)
    {
      printf("子进程, pid：%d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt--);
      sleep(1);
    }
  //运行完
  //1. 代码完，结果对
  //2. 代码完，结果不对
  //3. 代码没跑完，出异常了
  exit(10);//进程退出
  }

  //父进程
  sleep(8);
  int status = 0;
  pid_t ret = waitpid(id, &status, 0);
  if(id > 0)
  {
    printf("wait success: %d, sig number: %d, child exit code:%d\n",
        ret, (status & 0x7F), (status >> 8) & 0xFF);
  }
  sleep(5);

  return 0;
}
