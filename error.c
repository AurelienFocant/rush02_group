#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>

void	ft_putstr(char *str);

int	empty_arg(int argc, char **argv)
{
	if (argc == 2)
	{
		if (argv[1][0] == '\0')
		{
			ft_putstr("Error\n");
			return (-1);
		}
	}
	return (0);
}

int	argv_zero_error(int argc, char **argv)
{
	if (argc == 2 && argv[1][0] == '0')
	{
		ft_putstr("Error\n");
		return (-1);
	}
	if (argc == 3 && argv[2][0] == '0')
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}

int	argv_error(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 2)
	{
		while (argv[1][i])
		{
			if (argv[1][i] < '0' || argv[1][i] > '9')
			{
				ft_putstr("Error\n");
				return (-1);
			}
			i++;
		}
	}
	if (argc == 3)
	{
		while (argv[2][i])
		{
			if (argv[2][i] < '0' || argv[2][i] > '9')
			{
				ft_putstr("Error\n");
				return (-1);
			}
			i++;
		}
	}
	return (0);
}

int	argc_error(int argc)
{
	if (argc != 2 && argc != 3)
	{
		ft_putstr("Error\n");
		return (-1);
	}
	return (0);
}
