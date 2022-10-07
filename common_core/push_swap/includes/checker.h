#ifndef CHECKER_H
# define CHECKER_H
# include <stdlib.h>
# include <unistd.h>
#include <fcntl.h>
# include "push_swap.h"

char			*ft_strchr(char *s, char c);
char			*ft_strcpy(char *dest, char *src);
char			*ft_strdup(char *s);
char			*ft_substr(char *str, unsigned int start, unsigned int len);
int				get_next_line(int fd, char **line);
#endif