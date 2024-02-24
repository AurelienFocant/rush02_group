#include <string.h>
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

void ft_print_numero(char *nbr)
{
	char *keys[] = {"0", "1", "2", "3", "4", "30", "40"};
	int  intkeys[] = {0, 1, 2, 3, 4, 30, 40};
	char *values[] = {"one", "two", "three", "four", "thirty", "fourty"};

	char to_find;
	int int_to_find;
	char *to_write;

	int len = strlen(nbr);


	int i = len;
	while (i > 0)
	{
		int_to_find = atoi(&nbr[len - i]) * pow(10, i);
	
		int j = 0;
		while (j < 6)
		{
			if (int_to_find == intkeys[j])
			{
					to_write = values[j];
				break;
			}
			j++;
		}

		printf("%s ", to_write);
		i--;
	}
}


int main()
{
	ft_print_numero("42");
}
