#include <unistd.h>

int	argv_zero_error(int argc, char **argv);
int	argv_error(int argc, char **argv);
int	argc_error(int argc);
void	ft_putstr(char *str);

int main(int argc, char **argv)
{
	if (argv_zero_error(argc, argv) || argv_error(argc, argv) || argc_error(argc))
	{
		ft_putstr("Error\n");
		return (0);
	}

	return (0);
}
