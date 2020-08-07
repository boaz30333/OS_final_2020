#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

int count = 0;
void addCount(int signum)
{
    count++;
}

void printCount(int signum)
{
    printf("No. of recived signal: %d", count);
    exit(0);
}

int main(int argc, char *argv[])
{

    if (signal(SIGUSR1, printCount) == SIG_ERR)
    {
        printf("cannot catch SIGUSR1");
    }
    if (signal(SIGINT, addCount) == SIG_ERR)
    {
        printf("cannot catch SIGUSR1");
    }
    while (1)
    {
    }
}