/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_num.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:53:21 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 18:53:30 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRITE_NUM_H
# define WRITE_NUM_H

# include <unistd.h>

void	ft_find_index(char c, int pos, char **keys);
void	ft_print_num(char c, int pos, char **keys, char **values);
void	ft_print_nb(char *nbr, char **keys, char **values);

#endif
