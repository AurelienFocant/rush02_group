#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void ft_putnbr(int n)
{
	if (n > 10)
	{
		ft_putnbr(n / 10);
	}
	ft_putchar((n % 10) + '0');
}

void ft_print_number(int n)
{
	int keys[] = {0, 1, 2, 3, 40, 50};
	char *values[] = {"zero", "one", "two", "three", "fourty", "fifty"};

	int to_find;
	char *to_write;
	int a = 10;

	if (n > 10)
		ft_print_number(n / 10);

	int x = 0;
	while (x < 10)
	{
		if (n % 10  == x)
		{
			to_find = x;
			break;
		}
		x++;
	}
	
	int i = 0;
	while (i < 6)
	{
		if (to_find == keys[i])
		{
			to_write = values[i];
			break;
		}
		i++;
	}	

	printf("%s", to_write);

	printf(" ");

}

int main()
{
	ft_print_number(32);
}
