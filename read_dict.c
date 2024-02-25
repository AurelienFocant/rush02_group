/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_dict.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: afocant <afocant@student.s19.be>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 21:58:08 by afocant           #+#    #+#             */
/*   Updated: 2024/02/25 22:25:57 by afocant          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "header.h"


char	*ft_fill_word(char *str)
{
	int		len;
	char	*word;
	int		i;

	len = ft_lensep(str);
	word = malloc(sizeof(char) * (len + 1));
	if (word == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		word[i] = *str;
		str++;
		i++;
	}
	word[i] = '\0';
	return (word);
}

void	ft_fill_keys(char **keys, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			keys[i] = ft_fill_word(str); 
			i++;
			while (ft_isnum(*str))
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

void	ft_fill_values(char **values, char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		while (!ft_isalpha(*str) && *str)
			str++;
		if (ft_isalpha(*str) && *str)
		{
			values[i] = ft_fill_word(str); 
			i++;
			while (ft_isalpha(*str))
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
}

void	ft_free_all(char **keys, char **values, char *str)
{
	ft_free(keys);
	ft_free(values);
	free(keys);
	free(values);
	free(str);
}

int	main(int argc, char **argv)
{
	char	*str;
	char	**keys;
	char	**values;
	char	*file;	

	if (empty_arg(argc, argv) == -1)
		return (-1);
	if (argv_zero_error(argc, argv) == -1)
		return (-1);
	if (argv_error(argc, argv) == -1)
		return (-1);
	if (argc_error(argc) == -1)
		return (-1);
	file = "numbers.dict";
	if (argc == 3)
		file = argv[1];
	str = ft_copydict_instring(file, ft_count_chars(file));
	keys = ft_allocate_array(ft_count_lines(str));
	values = ft_allocate_array(ft_count_lines(str));
	ft_fill_keys(keys, str);
	ft_fill_values(values, str);
	if (argc == 3)
		ft_print_number(argv[2], keys, values);
	if (argc == 2)
		ft_print_number(argv[1], keys, values);
	ft_free_all(keys, values, str);
}
