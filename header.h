#ifndef HELPER_H
# define HELPER_H

#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>

int		ft_isnum(char c);
int		ft_isalpha(char c);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
void	ft_putstr(char *str);
int		ft_lensep(char *str);
void	ft_free(char **ptr);
int		ft_count_chars(char *dict);
int		ft_count_lines(char *str);
char	**ft_allocate_array(int size);
char	*ft_copydict_instring(char *dict, int size);
int		ft_find_index(char *str, char **keys);
void	ft_print_zero(char c, char **keys, char **values);
void	ft_print_hundreds(char c, char **keys, char **values);
void	ft_print_tens(char c, char d, char **keys, char **values);
void	ft_print_dozens(char c, char **keys, char **values);
void	ft_print_units(char c, char **keys, char **values);
void	ft_print_number(char *nbr, char **keys, char **values);
int		empty_arg(int argc, char **argv);
int		argv_zero_error(int argc, char **argv);
int		argv_error(int argc, char **argv);
int		argc_error(int argc);


#endif
