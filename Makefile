CC = gcc

CFLAGS += -Wall -Werror -Wextra

EXEC = rush-02

SRC = \
	  write_num.c\
	  read_dict.c\
	  helpers.c\
	  helpers2.c\
	  ft_read_helpers.c\
	  ft_write_helpers.c\
	  ft_write_helpers2.c\
	  error.c


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

helpers2.o : helpers2.c
	$(CC) $(CFLAGS) -o $@ -c $<

ft_read_helpers.o : ft_read_helpers.c
	$(CC) $(CFLAGS) -o $@ -c $<

ft_write_helpers.o : ft_write_helpers.c
	$(CC) $(CFLAGS) -o $@ -c $<
	
ft_write_helpers2.o : ft_write_helpers2.c
	$(CC) $(CFLAGS) -o $@ -c $<

error.o : error.c
	$(CC) $(CFLAGS) -o $@ -c $<

clean :
	rm -rf $(OBJ)

fclean : clean
	rm -rf $(EXEC)

re : fclean all
