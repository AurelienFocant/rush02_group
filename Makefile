CC = gcc

CFLAGS += -Wall -Werror -Wextra

EXEC = rush-02

SRC = \
	  write_num.c\
	  read_dict.c\
	  helpers.c\
	  ft_read_helpers.c\


OBJ = $(SRC:.c=.o)


all : $(EXEC)

$(EXEC) : $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

write_num.o : write_num.c
	$(CC) $(CFLAGS) -o $@ -c $<

read_dict.o : read_dict.c
	$(CC) $(CFLAGS) -o $@ -c $<

helpers.o : helpers.c
	$(CC) $(CFLAGS) -o $@ -c $<

ft_read_helpers.o : ft_read_helpers.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
