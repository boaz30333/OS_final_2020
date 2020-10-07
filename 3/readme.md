how to run:
1. use 'make' command to compile the program
2. run the progrm in this way " sudo ./set_policy  
|number denote the policy| |number denote the priority| "

    note: 
    SCHED_OTHER(0) min/max priority    : 0/0
    SCHED_FIFO(1) min/max priority     : 1/99
    SCHED_RR(2) min/max priority       : 1/99
    SCHED_BATCH(3) min/max priority    : 0/0 - we doesnt required but also working
    SCHED_IDLE(5) min/max priority     : 0/0
    SCHED_DEADLINE(6) min/max priority   : 

3. you can watch the policy and priority of the program before changing in before.txt
   and the result after changing in after.txt

