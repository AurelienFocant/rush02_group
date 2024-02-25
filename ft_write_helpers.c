void	ft_print_zero(char c, char **keys, char **values)
{
	char str[2];
	int index;
	str[0] = c;
	str[1] = '\0';

	index = ft_find_index(str, keys);
	ft_putstr(values[index]);
	ft_putstr("\n");
}

void	ft_print_hundreds(char c, char **keys, char **values)
{
	int index;
	char str[2];

	str[0] = c;
	str[1] = '\0';

	if (c != 0)
	{
		index = ft_find_index(str, keys);
		ft_putstr(values[index]);
		index = ft_find_index("100", keys);
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

	index = ft_find_index(str, keys);
	ft_putstr(values[index]);
}

void	ft_print_dozens(char c, char **keys, char **values)
{
	int index;
	char str[3];

	str[0] = c;
	str[1] = '0';
	str[2] = '\0';

	if (c != 0)
	{
		index = ft_find_index(str, keys);
		ft_putstr(values[index]);
	}
}

void	ft_print_units(char c, char **keys, char **values)
{
	char str[2];
	int index;

	str[0] = c;
	str[1] = '\0';

	if (c != 0)
	{
		index = ft_find_index(str, keys);
		ft_putstr(values[index]);
	}
}
