#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

void	ft_print_number(char *nbr, char **keys, char **values);
int	ft_isnum(char c);
int	ft_isalpha(char c);
int	ft_lensep(char *str);

int	ft_count_chars(char *dict)
{
	int		fd;
	int		count_chars;
	char	buff;

	fd = open(dict, 0);
	count_chars = 0;
	while (read(fd, &buff, 1))
	{
		count_chars++;
	}
	close(fd);
	return (count_chars);
}

char	*ft_copydict_instring(char *dict, int size)
{
	char	*str;
	int		fd;
	int		i;	
	char	buff;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	fd = open(dict, 0);
	i = 0;
	while (read(fd, &buff, 1))
	{
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
	close(fd);
	return (str);
}

int	ft_count_lines(char *str)
{
	int	count;

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

char	**ft_allocate_array(int size)
{
	char	**arr;

	arr = malloc(sizeof(char *) * (size + 1));
	if (arr == NULL)
		return (NULL);
	arr[size] = 0;
	return (arr);
}

char	*ft_fill_word(char *str)
{
	int		len;
	char	*word;
	int		i;

	len = ft_lensep(str);
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
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
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			keys[i] = ft_fill_word(str); 
			i++;
			while (ft_isnum(*str))
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

void	ft_fill_values(char **values, char *str)
{
	int	i;

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
			while (ft_isalpha(*str))
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr[i]);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**keys;
	char	**values;
	char	*file;	

	if (argc < 2 || argc > 3)
		return (1);
	file = "numbers.dict";
	if (argc == 3)
		file = argv[1];
	str = ft_copydict_instring(file, ft_count_chars(file));
	keys = ft_allocate_array(ft_count_lines(str));
	values = ft_allocate_array(ft_count_lines(str));
	ft_fill_keys(keys, str);
	ft_fill_values(values, str);
	if (argc == 3)
		ft_print_number(argv[2], keys, values);
	if (argc == 2)
		ft_print_number(argv[1], keys, values);
	ft_free(keys);
	ft_free(values);
	free(keys);
	free(values);
	free(str);
}
