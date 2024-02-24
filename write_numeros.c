#include <string.h>
#include <stdio.h>

/* read this file second
 * and start at the bottom
 * above are only help functions
 */

int	ft_find_index(char c, int pos, char **keys)
{
	int i;
	int count;

	/* to be replaced by line_count
	 * == size of keys[]
	 * now i think about it :p
	 */
	count = 40;

	i = 0;
	while (i < count)
	{
		if (pos == 1)
		{
			// needs exceptions for 10->19
			if (c == keys[i][0] && '0' == keys[i][1])
				return i;
		}

		else if (c == keys[i][0])
			return i; 
		i++;
	}
	return (i);
}

void	ft_print_numero(char c, int pos, char **keys, char **values)
{
	/* feature missing : if just 0 write zero, or "and"
	 * like in "one hundrer AND ..."
	 */

	/* could probably be very much simplified
	 */

	if (pos == 0)
	{
		if (c != '0')
		{
			int a = ft_find_index(c, pos, keys);
			printf("%s ", values[a]);
			printf("hundred ");
		}
	}

	if (pos == 1)
	{
		if (c != '0')
		{
			int a = ft_find_index(c, pos, keys);
			printf("%s ", values[a]);
		}
	}

	if (pos == 2)
	{
		if (c != '0')
		{
			int a = ft_find_index(c, pos, keys);
			printf("%s ", values[a]);
		}
	}
}

void	ft_print_number(char *nbr, char **keys, char **values)
{
	
	int len = strlen(nbr);
	int pos;
	
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

	
	/* could be simplified in this ?
	 * pos = len - len % 3 ?
	 */
	/* it s just the starting position
	 * notice pos++ down below
	 */
	if (len % 3 == 0)
		pos = 0;
	else if (len % 3 == 2)
		pos = 1;
	else if (len % 3 == 1)
		pos = 2;

	
	/* goes through every digit of the nbr
	 * and get its position in keys array
	 * prints it according to its position
	 * == if he s hundreds, dozens or units
	 */
	int i = 0;
	while (i < len)
	{
		ft_print_numero(nbr[i], pos, keys, values);
		pos++;
		i++;
	}
}
