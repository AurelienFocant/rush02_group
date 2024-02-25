/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 15:00:58 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 20:20:35 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../header_files/built_array.h"
#include "../header_files/classics.h"
#include "../header_files/cpy_dict.h"
#include "../header_files/helpers.h"
#include "../header_files/print_digit.h"
#include "../header_files/write_num.h"

int	ft_count_chars(int fd)
{
	int		count_chars;
	char	buff;

	count_chars = 0;
	while (read(fd, &buff, 1))
		count_chars++;
	return (count_chars);
}

int	ft_isalpha(char c)
{
	if (c >= 'A' && c <= 'Z')
		return (1);
	else if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_isnum(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}
