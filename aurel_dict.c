#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

int	ft_count_chars(int fd)
{
	int count_chars;
	char buff;

	count_chars = 0;
	while (read(fd, &buff, 1))
	{
		count_chars++;
	}
	return count_chars;
}

char *ft_allocate_string(int length)
{
	char *str;

	str = malloc(sizeof(char) * (length + 1));
	return (str);
}

void ft_copydict_instring(char *str, int fd)
{
	int i;	
	char buff;

	i = 0;
	while (read(fd, &buff, 1))
	{
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
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

int		ft_lensep(char *str)
{
	int i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != ':')
		i++;
	return (i);
}

char	*ft_fill_word(char *str)
{
	int len;
	char *word;
	int i;

	len = ft_lensep(str);
	word = malloc(sizeof(char) * (len + 1));
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

int main(int argc, char **argv)
{
	int fd;
	int char_count;
	char *str;
	int line_count;
	char **keys;
	char **values;

	if (argc != 2)
		return (1);

	fd = open(argv[1], 0);
	char_count = ft_count_chars(fd);
	close(fd);

	str = ft_allocate_string(char_count);
	fd = open(argv[1], 0);
	ft_copydict_instring(str, fd);

	line_count = ft_count_lines(str);
	keys = malloc(sizeof(char *) * (line_count + 1));
	keys[line_count] = 0;
	values = malloc(sizeof(char *) * (line_count + 1));
	values[line_count] = 0;

	ft_fill_keys(keys, str);
	ft_fill_values(values, str);

	int i = 0;
	while (keys[i])
	{
		printf("key: %s value: %s\n", keys[i], values[i]);	
		i++;
	}

	



	ft_free(keys);
	ft_free(values);

	free(str);
}
