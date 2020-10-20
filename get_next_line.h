#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
//# include <stdio.h> //teste, apagar

/*
** gnl
*/
int		get_next_line(int fd, char **line);
char	*ft_readbuf(int fd, int *r_fd);
char	*ft_justdoit(char *s_line, char **line, int *r_fd);
/*
** gnl Utils
*/
size_t	ft_strlen(const char *str);
char	*ft_strjoin(char const *s1, char const *s2);
size_t	ft_strlcpy(char *dest, const char *src, size_t size);
int		ft_strchr_bn(const char *s);
void	ft_strclean(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
void	ft_strdel(char **s);
#endif