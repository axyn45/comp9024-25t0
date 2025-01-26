CC      = gcc
CFLAGS  = -Wall -Werror -std=c11

connectedComponents : connectedComponents.o graphCC.o
	$(CC) $(CFLAGS) -o connectedComponents connectedComponents.o graphCC.o

connectedComponents.o : connectedComponents.c graphCC.h
	$(CC) $(CFLAGS) -c connectedComponents.c

graphCC.o : graphCC.c graphCC.h
	$(CC) $(CFLAGS) -c graphCC.c

clean : 
	rm -f *.o connectedComponents