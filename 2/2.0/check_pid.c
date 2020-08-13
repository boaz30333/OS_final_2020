#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
int main(int argc, char *argv[])
{
    int status;
    long pid;
    pid = atol(argv[1]);  // convert string to long
    status = kill(pid, 0);
    if (status == 0)
        printf("Process %ld exists", pid);
    else if (errno == EPERM)
        printf("Process %ld exists but we have no permission", pid);
    else if (errno == ESRCH)
        printf("Process %ld does not exist", pid);

exit(0);
}