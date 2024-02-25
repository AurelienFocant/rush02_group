#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_number(char *nbr, char **keys, char **values);

void	ft_putstr(char *str)
{
	int		i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_copydict_instring(char *str, char **argv)
{
	int	fd;
	int i;
	char buff;

	fd = open(argv[1], 0);
	if (fd == -1)
		return (-1);
	i = 0;
	while (read(fd, &buff, 1))
	{
		if (read(fd, &buff, 1) == -1)
		{
			ft_putstr("Dict Error\n");
			return (-1);
		}
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}


/* counts lines but only
 * if theres a numerical char on it
 * to be sure it doesn't count
 * any empty line
 */
int	ft_count_lines(char *str)
{
	int count;

	count = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			count++;
			while (ft_isnum(*str) && *str)
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
	return (count);
}


/* basically a ft_strlen
 * but adds more stopping points
 * than just '\0'
 */
int		ft_lensep(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != ':')
		i++;
	return (i);
}


/* we enter this function when
 * we find a key == numero in the dict
 * or a value == a letter in the dict
 * we find the len of that word until next sep
 * and malloc enough space
 * + '\0' of course
 */
/* we can then copy char by char
 * using the pointer from original string
 */
char	*ft_fill_word(char *str)
{
	int len;
	char *word;
	int i;

	len = ft_lensep(str);
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	i = 0;
	while (i < len)
	{
		word[i] = *str;
		str++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_fill_keys(char **keys, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			keys[i] = ft_fill_word(str);
			i++;
			while(ft_isnum(*str))
					str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

void	ft_fill_values(char **values, char *str)
{
	int i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		while (!ft_isalpha(*str) && *str)
			str++;
		if (ft_isalpha(*str) && *str)
		{
			values[i] = ft_fill_word(str);
			i++;
			while(ft_isalpha(*str))
					str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

/* free the whole array of char*
 */
void	ft_free(char **ptr)
{
	int i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
}

int	ft_count_chars(char **argv)
{
	int		fd;
	int		char_count;
	char	buff;

	fd = open(argv[1], 0);
	if (fd == -1)
	{
		ft_putstr("Dict Error\n");
		return (-1);                 
	}
	while (read(fd, &buff, 1))
	{
		if (read(fd, &buff, 1) == -1)
		{
			ft_putstr("Dict Error\n");
			return (-1);
		}
		char_count++;
	}
	close(fd);
	return (char_count);
}

char *ft_allocate_string(char_count)
{
	char *str;

	str = malloc(sizeof(char) * (char_count + 1));
	if (str == NULL)
	{
		ft_putstr("Error\n");
		return (NULL);
	}
	return (str);
}


int ft_allocate_keys_values(char **keys, char **values, int line_count)
{
	keys = malloc(sizeof(char *) * (line_count + 1));
	if (keys == NULL)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	keys[line_count] = 0;
	values = malloc(sizeof(char *) * (line_count + 1));
	if (values == NULL)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	values[line_count] = 0;
	return (0);
}

int yo(int argc, char **argv)
{
	int fd;
	int char_count;
	char *str;
	int line_count;
	char **keys;
	char **values;

	if (argc == 1 || argc > 3)
		return (-1);

	char_count = ft_count_chars(argv);
	if (char_count == -1)
		return (-1);

	ft_allocate_string(char_count);

	
	if (ft_copydict_instring(str, argv) == -1)
		return (-1);

	line_count = ft_count_lines(str);

	if (ft_allocate_keys_values(keys, values, char_count) == -1)
		return (-1);



	ft_fill_keys(keys, str);
	ft_fill_values(values, str);


	/* this just to see that the arrays are correctly filled
	 * will be deleted
	 */
	
	int i = 0;
	while (keys[i])
	{
		printf("key: %s value: %s\n", keys[i], values[i]);
		i++;
	}
	

	/* goes to the next file
	 * and pass in the arrays
	 * both files could use lots of cleaning
	 * and lots of bugs still
	 */
	//ft_print_number(argv[2], keys, values);

	/* lets not forget to free everything,
	 * should check for null pointers,
	 * etc etc
	 * could run valgrind when file a bit cleaner
	 */
	ft_free(keys);
	ft_free(values);
	free(keys);
	free(values);

	free(str);
	return 0;
}

int main(int argc, char **argv)
{
	printf("%i\n", yo(argc, argv));
}
