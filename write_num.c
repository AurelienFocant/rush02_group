#include <unistd.h>

#define HUNDREDS 0
#define DOZENS 1
#define UNITS 2

int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_find_index(char *str, char **keys);
void	ft_print_zero(char c, char **keys, char **values);
void	ft_print_hundreds(char c, char **keys, char **values);
void	ft_print_tens(char c, char d, char **keys, char **values);
void	ft_print_dozens(char c, char **keys, char **values);
void	ft_print_units(char c, char **keys, char **values);


void	ft_print_orderof_magnitude(int mag, char **keys, char **values)
{
	int index;

		if (mag > 0)
		{
			if (mag == 3)
			{
				index = ft_find_index("1000000000", keys);
				ft_putstr(values[index]);
				ft_putstr(" ");
			}
			else if (mag == 2)
			{
				index = ft_find_index("1000000", keys);
				ft_putstr(values[index]);
				ft_putstr(" ");
			}
			else if (mag == 1)
			{
				index = ft_find_index("1000", keys);
				ft_putstr(values[index]);
				ft_putstr(" ");
			}
		}
}



void	ft_print_number(char *nbr, char **keys, char **values)
{
	
	int len = ft_strlen(nbr);
	int pos;
	int mag;
	
	if (len == 1 && nbr[0] == '0')
		ft_print_zero(nbr[0], keys, values);
	if (len % 3 == 0)
		pos = HUNDREDS;
	else if (len % 3 == 2)
		pos = DOZENS;
	else if (len % 3 == 1)
		pos = UNITS;
	mag = (len - 1) / 3;
	int i = 0;
	while (i < len)
	{
		if (pos == HUNDREDS)
		{
			ft_print_hundreds(nbr[i], keys, values);
			ft_putstr(" ");
			pos = (pos + 1) % 3;
			i++;
		}
		else if (pos == DOZENS)
		{
			if (nbr[i] == '1')
			{
				ft_print_tens(nbr[i], nbr[i + 1], keys, values);
				if (mag > 0)
					ft_putstr(" ");
				else if (mag == 0)
					ft_putstr("\n");
				ft_print_orderof_magnitude(mag, keys, values);
				mag--;
				pos = (pos + 2) % 3;
				i += 2;
			}
			else
			{
				ft_print_dozens(nbr[i], keys, values);
				ft_putstr(" ");
				pos = (pos + 1) % 3;
				i++;
			}
		}
		else if (pos == UNITS)
		{
			ft_print_units(nbr[i], keys, values);
			if (mag > 0)
				ft_putstr(" ");
			else if (mag == 0)
				ft_putstr("\n");
			ft_print_orderof_magnitude(mag, keys, values);
			mag--;
			pos = (pos + 1) % 3;
			i++;
		}
	}
}
