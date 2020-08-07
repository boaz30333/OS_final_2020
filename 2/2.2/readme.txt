how to run:
open two new terminals in this directory

on the first one : 
1. run make command to compile the files
2. run server in as new thread in this way : root@DESKTOP: ./server&
3. look at the thread process number and save it in your mind. 

on the second one: 
run new command : "./client <server pid that you saved in your mind> 2 1000 
run another command : ./client <same server pid> 10 1

result : 
In the first terminal will show the number of reccived signals