#include "process.h"

void ProcessOn() //函数定义
{
  int cnt = 0;
  char bar[NUM];
  memset(bar, '\0', sizeof(bar));
  const char *label = "|\\-/";

  //101 times
  while(cnt <= 100)
  {
    printf("[%-100s][%d%%][%c]\r", bar, cnt, label[cnt % 4]);
    fflush(stdout);
    bar[cnt++] = STYLE;
    usleep(50000);
  }
  printf("\n");
}
