#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>

int	ft_isnum(char c);
void	ft_putstr(char *str);

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

int	ft_count_chars(char *dict)
{
	int		fd;
	int		count_chars;
	char	buff;

	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict error\n");
		return (-1);
	}
	count_chars = 0;
	while (read(fd, &buff, 1))
	{
		count_chars++;
	}
	close(fd);
	return (count_chars);
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

char	*ft_copydict_instring(char *dict, int size)
{
	char	*str;
	int		fd;
	int		i;
	char	buff;

	str = malloc(sizeof(char) * (size + 1));
	if (str == NULL)
		return (NULL);
	fd = open(dict, O_RDONLY);
	if (fd == -1)
	{
		ft_putstr("Dict error\n");
		return (NULL);
	}
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
