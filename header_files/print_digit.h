/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_digit.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 19:04:03 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 19:09:29 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINT_DIGIT_H
# define PRINT_DIGIT_H

void	ft_print_zero(char c, char **keys, char **values);
void	ft_print_hundreds(char c, char **keys, char **values);
void	ft_print_tens(char c, char d, char **keys, char **values);
void	ft_print_dozens(char cm char **keys, char **values);
void	ft_print_units(char c, char **keys, char **values);

#endif
