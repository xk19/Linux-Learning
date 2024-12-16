#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define USER "USER"
#define MYPWD "PWD"


//int main(int argc, char *argv[], char *env[])
int main(int argc, char *argv[])
{
  if(argc != 2)
  {
    printf("Usage:\n\t%s [-a/-b/-ab]\n",argv[0]);
    return 1;
  }
  if(strcmp("-a", argv[1]) == 0)
  {
    printf("功能a\n");
  }
  if(strcmp("-b", argv[1]) == 0)
  {
    printf("功能b\n");
  }
  if(strcmp("-ab", argv[1]) == 0)
  {
    printf("功能ab\n");
  }
  /*
   for(int i = 0; env[i]; i++)
   {
     printf("env[%d]:%s\n",i, env[i]);
   }
   */
  /*
  printf("%s\n", getenv(MYPWD));
  char *who = getenv(USER);
  if(strcmp(who, "root") == 0)
  {
     printf("user:%s\n", who);
     printf("user:%s\n", who);
     printf("user:%s\n", who);
  }
  else{
    printf("权限不足");
  }
  */
}
