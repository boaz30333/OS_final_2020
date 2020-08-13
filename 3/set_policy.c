

#define _GNU_SOURCE
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
#include <sched.h>
#include <linux/sched.h>
#include <sys/syscall.h>
#include <linux/types.h>
#include <unistd.h>
#include <string.h>
#include <sys/time.h>
#include <sys/resource.h>

    
struct sched_attr
{
    __u32 size;
    __u32 sched_policy;
    __u64 sched_flags;
    __s32 sched_nice;
    __u32 sched_priority;
    __u64 sched_runtime;
    __u64 sched_deadline;
    __u64 sched_period;
};

int sched_setattr(pid_t pid,
                  const struct sched_attr *attr,
                  unsigned int flags)
{
    return syscall(__NR_sched_setattr, pid, attr, flags);
}

int sched_getattr(pid_t pid,
                  struct sched_attr *attr,
                  unsigned int size,
                  unsigned int flags)
{
    return syscall(__NR_sched_getattr, pid, attr, size, flags);
}

int main(int argc, char *argv[])
{
    int policy = atoi(argv[1]);
    int priority = atoi(argv[2]);
    struct sched_param s_param;
    struct sched_attr s_attr;
    long pid =  (long)getpid();
struct sched_attr before_s_attr;
struct sched_attr result_s_attr;
        printf("my pid is: %ld \n",pid);

                if (sched_getattr(0, &before_s_attr,sizeof(before_s_attr), 0) == -1)
        {
            perror("sched_getattr");
            exit(EXIT_FAILURE);
        }
FILE * fpa;
fpa= fopen("before.txt","w+");
fprintf(fpa,"pid %ld's current scheduling policy: %lu \n",pid,(unsigned long)before_s_attr.sched_policy);
fprintf(fpa,"pid %ld's current scheduling priority: %lu \n",pid,(unsigned long)before_s_attr.sched_priority);
fclose(fpa);

  

    if (policy == 6)
    {
        s_attr.size = sizeof(struct sched_attr);
        s_attr.sched_policy = SCHED_DEADLINE;
        s_attr.sched_flags = 0;
        s_attr.sched_nice = 0;
        s_attr.sched_priority = priority;
        s_attr.sched_runtime = 100 * 1000;
        s_attr.sched_period = 1000 * 1000;
        s_attr.sched_deadline = 1000 * 1000;
        if (sched_setattr(0, &s_attr, 0) == -1)
        {
            perror("sched_setattr");
            exit(EXIT_FAILURE);
        }

    }
    else
    {
        s_param.sched_priority = priority;
        if (sched_setscheduler(0, policy, &s_param) == -1)
        {
            perror("sched_setscheduler");
            exit(EXIT_FAILURE);
        }
 

    }
                if (sched_getattr(0, &result_s_attr,sizeof(result_s_attr), 0) == -1)
        {
            perror("sched_getattr");
            exit(EXIT_FAILURE);
        }
//FILE * fpa;
fpa= fopen("after.txt","w+");
fprintf(fpa,"pid %ld's current scheduling policy: %lu \n",pid,(unsigned long)result_s_attr.sched_policy);
fprintf(fpa,"pid %ld's current scheduling priority: %lu \n",pid,(unsigned long)result_s_attr.sched_priority);
fclose(fpa);
    printf("the result in before.txt and after.txt files after chrt command but \nyou can also execute chrt from other trminal and then kill this process by ctrl^z \n");

while(1){

}
    exit(0);
}

