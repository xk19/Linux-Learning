#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
  printf("process is running...\n");
  pid_t id = fork();
  assert(id != -1);

  if(id == 0)
  {
    sleep(1);

    execl("./mycpp", "mycpp", NULL);
    exit(1);
  }

  int status = 0;
  pid_t ret = waitpid(id, &status, 0);
  if(ret > 0) printf("wait success: exit code: %d, sig: %d\n", (status>>8)&0xFF, status & 0x7F);

  return 0;
}
