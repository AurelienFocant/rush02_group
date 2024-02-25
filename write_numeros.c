#include <string.h>
#include <stdio.h>
#include <unistd.h>

#define HUNDREDS 0
#define DOZENS 1
#define UNITS 2

/* read this file second
 * and start at the bottom
 * above are only help functions
 */


int		ft_strcmp(char *s1, char *s2)
{
	int i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}


void	ft_putstr(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int		ft_find_index(char c, int pos, char **keys)
{
	int i;

	i = 0;
	while (keys[i])
	{
		if (pos == DOZENS)
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

int		 ft_find_index_str(char *str, char **keys)
{
	int i;

	i = 0;
	while (keys[i])
	{
		if (ft_strcmp(str, keys[i]) == 0)
			return (i);
		i++;
	}
	return (i);
}

void	ft_print_zero(char c, char **keys, char **values)
{
	int index;

	index = ft_find_index(c, 2, keys);
	ft_putstr(values[index]);
	ft_putstr("\n");
}

void	ft_print_hundreds(char c, char **keys, char **values)
{
	int pos;
	int index;

	pos = HUNDREDS;

	if (c != 0)
	{
		index = ft_find_index(c, pos, keys);
		ft_putstr(values[index]);
		index = ft_find_index_str("100", keys);
		ft_putstr(" ");
		ft_putstr(values[index]);
	}
}

void	ft_print_tens(char c, char d, char **keys, char **values)
{
	char str[3];
	int index;

	str[0] = c;
	str[1] = d;
	str[2] = '\0';	

	index = ft_find_index_str(str, keys);
	ft_putstr(values[index]);
}

void	ft_print_dozens(char c, char **keys, char **values)
{
	int pos;
	int index;

	pos = DOZENS;

	if (c != 0)
	{
		index = ft_find_index(c, pos, keys);
		ft_putstr(values[index]);
	}
}

void	ft_print_units(char c, char **keys, char **values)
{
	int pos;
	int index;

	pos = UNITS;

	if (c != 0)
	{
		index = ft_find_index(c, pos, keys);
		ft_putstr(values[index]);
	}
}

void	ft_print_orderof_magnitude(int mag, char **keys, char **values)
{
	int index;

		if (mag > 0)
		{
			if (mag == 3)
			{
				index = ft_find_index_str("1000000000", keys);
				ft_putstr(values[index]);
				ft_putstr(" ");
			}
			else if (mag == 2)
			{
				index = ft_find_index_str("1000000", keys);
				ft_putstr(values[index]);
				ft_putstr(" ");
			}
			else if (mag == 1)
			{
				index = ft_find_index_str("1000", keys);
				ft_putstr(values[index]);
				ft_putstr(" ");
			}
		}
}

void	ft_print_number(char *nbr, char **keys, char **values)
{
	
	int len = strlen(nbr);
	int pos;
	int mag;
	
	/* it s even a bit unclear to me still
	 * We basically need length of the numeric string
	 * to know which digit is in which position
	 */
	/* still lacks very important feature:
	 * know where the number is to be 
	 * able to write thousand, million etc
	 */
	/* also not forget to not print a space
	 * at the very last digit
	 * but a \n probably
	 */


	/* check if nbr is just 0
	 */	

	if (len == 1 && nbr[0] == '0')
		ft_print_zero(nbr[0], keys, values);

	/* starting position:
	 * 0 if hundreds
	 * 1 if dozens
	 * 2 if units
	 */
	if (len % 3 == 0)
		pos = HUNDREDS;
	else if (len % 3 == 2)
		pos = DOZENS;
	else if (len % 3 == 1)
		pos = UNITS;


	/* has to know how many groups
	 * of 3 numbers after the
	 * hundreds :
	 * 0 none
	 * 1 --> thousand
	 * 2 --> millions
	 * 3 --> billions
	 * more ?? For bonuses
	 * could % 3 and start at thousand again..
	 */
	mag = (len - 1) / 3;
	
	/* goes through every digit of the nbr
	 * and get its position in keys array
	 * prints it according to its position
	 * == if he s hundreds, dozens or units
	 */
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
