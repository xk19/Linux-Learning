#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

#define NUM 10

typedef void (*func_t)();

func_t handlerTask[NUM];

void task1()
{
  printf("handler task1\n");
}
void task2()
{
  printf("handler task2\n");
}
void task3()
{
  printf("handler task3\n");
}

void loadTask()
{
  memset(handlerTask, 0, sizeof(handlerTask));
  handlerTask[0] = task1;
  handlerTask[1] = task2;
  handlerTask[2] = task3;
}

int main()
{
  pid_t id = fork();
  
  if(id == 0)
  {
    //child
    int cnt = 5;
    while(cnt)
    {
      printf("子进程, pid：%d, ppid: %d, cnt: %d\n", getpid(), getppid(), cnt--);
      sleep(2);
    }
  //运行完
  //1. 代码完，结果对
  //2. 代码完，结果不对
  //3. 代码没跑完，出异常了
  exit(10);//进程退出
  }

  //父进程
  loadTask();
  int status = 0;
  while(1)
  {
    pid_t ret = waitpid(id, &status, WNOHANG);
    if(ret == 0)
    {
      //pid调用成功，子进程没有退出
      printf("wait done, but child is running...., parent running other things\n");
      for(int i = 0; handlerTask[i] != NULL; i++)
      {
        handlerTask[i]();
      }
    }
    else if(ret > 0)
    {
      //waitpid调用成功，子进程已经退出了
      printf("wait success, exit code: %d, sig: %d\n",(status>>8)&0xFF, status & 0x7F);
      break;
    }
    else
    {
      //waitpid调用失败
      printf("waipid call failed\n");
      break;
    }
    sleep(1); 
  }



  /*pid_t ret = waitpid(id, &status, 0);
  sleep(6);
  if(id > 0)
  {
    printf("wait success: %d, sig number: %d, child exit code:%d\n",
        ret, (status & 0x7F), (status >> 8) & 0xFF);
  }
  sleep(5);*/

  return 0;
}
