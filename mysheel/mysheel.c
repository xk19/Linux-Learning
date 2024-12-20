#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>

#define NUM 1024
#define OPT_NUM 64

char lineCommand[NUM];
char *myargv[OPT_NUM];

int main()
{
  while(1)
  {

    //输出提示符
    printf("用户名@主机名 当前路径# ");
    fflush(stdout);

    //获取用户输入
    char *s = fgets(lineCommand, sizeof(lineCommand)-1, stdin);
    assert(s != NULL);
    (void)s;

    //清除最后一个\n, abcd\n
    lineCommand[strlen(lineCommand)-1] = 0;
    
    //字符串切割
    myargv[0] = strtok(lineCommand, " ");

    int i = 1;
    while((myargv[i++]) = strtok(NULL, " "));

    //测试是否成功，条件编译
#ifdef DEBUG
    for(int i = 0; myargv[i]; i++)
    {
      printf("myargv[%d]: %s\n", i, myargv[i]);
    }
#endif

    //创建子进程，调用接口，执行命令
    pid_t id = fork();
    assert(id != -1);

    if(id == 0)
    {
      execvp(myargv[0], myargv);
      exit(1);
    }
    waitpid(id, NULL, 0);
  }

  return 0;
}
