/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   classics.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:05:52 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 19:59:50 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/built_array.h"
#include "../header_files/classics.h"
#include "../header_files/cpy_dict.h"
#include "../header_files/helpers.h"
#include "../header_files/print_digit.h"
#include "../header_files/write_num.h"

void	ft_putstr(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		write(1, &str[i], 1);
		i++;
	}
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] && s1[i] == s2[i])
		i++;
	return (s1[i] - s2[i]);
}
