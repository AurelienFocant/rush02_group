int	ft_strcmp(char *s1, char *s2);

int		 ft_find_index(char *str, char **keys)
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

