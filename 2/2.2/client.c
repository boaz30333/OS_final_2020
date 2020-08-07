#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>



int main(int argc, char *argv[])
{
    pid_t server=atol(argv[1]);
    int sig_type=atoi(argv[2]);
    int num=atoi(argv[3]);
if(sig_type==2){
    for(int i=0 ; i<num; ++i)
       kill(server, sig_type);
}
else if (sig_type==10){
    kill(server, sig_type);
}
return 0;
}