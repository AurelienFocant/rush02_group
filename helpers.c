int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_lensep(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != ':')
		i++;
	return (i);
}
