/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   built_array.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:11:35 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 19:59:41 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/built_array.h"
#include "../header_files/classics.h"
#include "../header_files/cpy_dict.h"
#include "../header_files/helpers.h"
#include "../header_files/print_digit.h"
#include "../header_files/write_num.h"

char	*ft_fill_word(char *str)
{
	int		len;
	char	*word;
	int		i;

	len = ft_lensep(str);
	word = malloc(sizeof(char) * (len + 1));
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
			keys[i] = ft_fill_word(str);
		i++;
		while (ft_isnum(*str))
			str++;
	}
	while (*str != '\n' && *str)
		str++;
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
