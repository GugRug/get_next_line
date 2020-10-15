#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h> //test
# include <fcntl.h>

/*
** gnl
*/
int	get_next_line(int fd, char **line);
void	ft_putbuf(char *buf, char *s_line);
void	ft_puts_line(char *s_line, char **line);
/*
** gnl Utils
*/
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
char	*ft_strchr(const char *s, int c);
void	ft_strclean(void *s, size_t n);
#endif