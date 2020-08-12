CC=gcc
FLAGS= -g -Wall

check_pid: check_pid.o
	$(CC) $(FLAGS) -o check_pid check_pid.o
		rm check_pid.o

check_pid.o: check_pid.c
	$(CC) $(FLAGS)  -c check_pid.c

.PHONY: clean
	
clean:
	rm -f *.o *.out check_pid 