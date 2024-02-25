/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_dict.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:01:49 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 20:18:47 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/built_array.h"
#include "../header_files/classics.h"
#include "../header_files/cpy_dict.h"
#include "../header_files/helpers.h"
#include "../header_files/print_digit.h"
#include "../header_files/write_num.h"

void	ft_copydict_instring(char *str, int fd)
{
	int		i;
	char	buff;

	i = 0;
	while (read(fd, &buff, 1))
	{
		str[i] = buff;
		i++;
	}
	str[i] = '\0';
}

int	ft_count_lines(char *str)
{
	int	count;

	count = 0;
	while (*str)
	{
		while (*str == '\n' && *str)
			str++;
		if (ft_isnum(*str) && *str)
		{
			count++;
			while (ft_isnum(*str) && *str)
				str++;
		}
		while (*str != '\n' && *str)
			str++;
	}
	return (count);
}

int	ft_lensep(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n' && str[i] != ' ' && str[i] != ':')
		i++;
	return (i);
}
