#include <errno.h>
#include <signal.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    signal(SIGCHLD, SIG_IGN);

    char szCmd[] = "lls *.cc";
    int status = system(szCmd);
    printf("CMD[%s]: status=%d errno=%d (%s)\n", szCmd, status, errno,
           strerror(errno));
    return 0;
}