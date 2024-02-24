#include <string.h>
#include <stdio.h>

int	ft_find_index(char c, int pos)
{
	char *keys[] =  {"0", "1", "2", "3", "4", "30", "40"};
	
	int i;
	int count;

	count = 7;

	i = 0;
	while (i < count)
	{
		if (pos == 1)
		{
			if (c == keys[i][0] && '0' == keys[i][1])
				return i;
		}

		else if (c == keys[i][0])
			return i; 
		i++;
	}
	return (i);
}

void	ft_print_numero(char c, int pos)
{
	char *values[] =  {"zero", "one", "two", "three", "four", "thirty", "fourty"};

	if (pos == 0)
	{
		if (c != '0')
		{
			int a = ft_find_index(c, pos);
			printf("%s ", values[a]);
			printf("hundred ");
		}
	}

	if (pos == 1)
	{
		if (c != '0')
		{
			int a = ft_find_index(c, pos);
			printf("%s ", values[a]);
		}
	}

	if (pos == 2)
	{
		if (c != '0')
		{
			int a = ft_find_index(c, pos);
			printf("%s ", values[a]);
		}
	}
}

void	ft_print_number(char *nbr)
{
	
	int len = strlen(nbr);
	int pos;
	
	
	if (len % 3 == 0)
		pos = 0;
	else if (len % 3 == 2)
		pos = 1;
	else if (len % 3 == 1)
		pos = 2;


	int i = 0;
	while (i < len)
	{
		ft_print_numero(nbr[i], pos);
		pos++;
		i++;
	}
}

int main()
{
	ft_print_number("432");
}
