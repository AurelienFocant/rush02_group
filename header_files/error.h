/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbenbell <sbenbell@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/25 18:39:02 by sbenbell          #+#    #+#             */
/*   Updated: 2024/02/25 18:53:00 by sbenbell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_H
# define ERROR_H

int	argv_zero_error(int argc, char **argv);
int	argv_error(int argc, char **argv);
int	argc_error(int argc);

#endif
