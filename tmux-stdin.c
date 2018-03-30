#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

void tmux_sendkeys(char *target_pane, char c)
{
  char buf[16];
  char *args[] = {"tmux", "send-keys", "-t", target_pane, buf, 0};
  int pid = fork();
  if (pid < 0)
    exit(1);

  if (pid == 0) {
    snprintf(buf, sizeof(buf), "0x%02x", c);
    execvp("/usr/local/bin/tmux", args);
    perror("execvp");
  } else {
    wait(NULL);
  }
}

int main(int argc, char **argv)
{
  char c;
  int rc;

  if (argc != 2) {
    printf("usage: %s <target-pane>\n", argv[0]);
    exit(1);
  }

  for (;;) {
    rc = fread(&c, 1, 1, stdin);
    if (rc != 1)
      break;

    tmux_sendkeys(argv[1], c);
  }

  return 0;
}
