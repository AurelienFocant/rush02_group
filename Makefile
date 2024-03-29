CC = gcc

CFLAGS += -Wall -Werror -Wextra

EXEC = rush-02

SRC = $(wildcard *.c)

OBJ = $(SRC:.c=.o)



all : $(EXEC)

maintest.o : maintest.c 
	$(CC) $(CFLAGS) -o $@ -c $<

error.o : error.c
	$(CC) $(CFLAGS) -o $@ -c $<

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

clean :
	rm -rf $(OBJ) 

fclean : clean
	rm -rf $(EXEC)	

re : fclean all
