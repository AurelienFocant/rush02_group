/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:14:09 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 20:00:28 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/built_array.h"
#include "../header_files/classics.h"
#include "../header_files/cpy_dict.h"
#include "../header_files/helpers.h"
#include "../header_files/print_digit.h"
#include "../header_files/write_num.h"

void	ft_print_zero(char c, char **keys, char **values)
{
	char	str[2];
	int		index;

	str[0] = c;
	str[1] = '\0';
	index = ft_find_index(str, keys);
	ft_putstr(values[index]);
	ft_putstr("\n");
}

void	ft_print_hundreds(char c, char **keys, char **values)
{
	int		index;
	char	str[2];

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
	char	str[3];
	int		index;

	str[0] = c;
	str[1] = d;
	str[2] = '\0';
	index = ft_find_index(str, keys);
	ft_putstr(values[index]);
}

void	ft_print_dozens(char c, char **keys, char **values)
{
	int		index;
	char	str[3];

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
	char	str[2];
	int		index;

	str[0] = c;
	str[1] = '\0';
	if (c != 0)
	{
		index = ft_find_index(str, keys);
		ft_putstr(values[index]);
	}
}
