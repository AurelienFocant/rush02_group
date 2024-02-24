CC = gcc

CFLAGS += -Wall -Werror -Wextra

EXEC = rush-02

SRC = $(wilcard *.c)



all : $(EXEC) fclean

$(EXEC) : main.o
	gcc $(CFLAGS) *.o -o rush-02  

main.o : main.c 
	gcc $(CFLAGS) -c main.c -o main.o

                                     # RAJOUTER TOUS LES .c

fclean : 
	rm -rf *.o
	rm -rf rush-02	
