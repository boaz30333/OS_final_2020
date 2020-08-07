#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sched.h>
#include <linux/sched.h>
int main(int argc, char *argv[])
{
    int policy;
    int priority;
struct sched_param sp;
	struct sched_attr attr1 = {
		.size = sizeof(struct sched_attr),

		.sched_policy = SCHED_DEADLINE,
		.sched_flags = 0,

		.sched_nice = 0,

		.sched_priority = 0,

		.sched_runtime =   100 * 1000,
		.sched_period =   1000 * 1000,
		.sched_deadline = 1000 * 1000,
	};
    policy = atoi(argv[1]);
    priority = atoi(argv[2]);
    if(policy==SCHED_DEADLINE)
sp.sched_priority= priority;

 
    if (sched_setscheduler(0, policy, &sp) == -1)
        errExit("sched_setscheduler");

while(1){

}
exit(0);
}