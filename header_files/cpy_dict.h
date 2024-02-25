/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cpy_dict.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:52:45 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 18:52:50 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CPY_DICT_H
# define CPY_DICT_H

# include <fcntl.h>

void	ft_copydict_instring(char *str, int fd);
int		ft_count_lines(char *str);
int		ft_lensep(char *str);

#endif
