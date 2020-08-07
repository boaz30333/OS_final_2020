CC=gcc
FLAGS= -g -Wall

all: client server cleano
client: client.o
	$(CC) $(FLAGS) -o client client.o
		rm client.o

server.o: server.c
	$(CC) $(FLAGS)  -c server.c

server: server.o
	$(CC) $(FLAGS) -o server server.o
		rm server.o

client.o: client.c
	$(CC) $(FLAGS)  -c client.c




.PHONY: clean cleano
	
clean:
	rm -f *.o *.out client server