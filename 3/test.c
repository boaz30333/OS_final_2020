#define _GNU_SOURCE
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sched.h>
#include <linux/sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <sys/syscall.h>
#include <pthread.h>
 
 /*
 #define _GNU_SOURCE
#include <signal.h>
#include <errno.h>
#include <stdlib.h>
#include <stdio.h>
 #include <sched.h>
#include <linux/sched.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <linux/unistd.h>
#include <linux/kernel.h>
#include <linux/types.h>
#include <sys/syscall.h>
#include <pthread.h>

 */
 int main(){
     int a=SCHED_DEADLINE ;
     int b = SCHED_FIFO; 1-99
     int c= SCHED_IDLE, 0
     SCHED_BATCH
     SCHED_RR,  1-99
     SCHED_OTHER 0
     deadline 
     printf()
 }