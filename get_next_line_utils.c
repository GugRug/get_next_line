#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*join;
	size_t	len;

	size_t	i;
	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2);
	i = 0;
	join = (char*)malloc(sizeof(char) * (len + 1));
	if (join == NULL)
		return (NULL);
	while (*s1 != '\0' && i < len)
		join[i++] = *(s1++);
	while (*s2 != '\0' && i < len)
		join[i++] = *(s2++);
	join[i] = '\0';
	return (join);
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = 0;
	j = 0;
	if (dest == src)
		return (0);
	while (src[j])
		j++;
	while (src[i] && i < size)
	{
		dest[i] = src[i];
		i++;
	}
	if (size > 0)
		dest[i] = '\0';
	return (j);
}

int		ft_strchr_bn(const char *s)
{
	int i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		return (i);
	return (-1);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	size_t	i;
	char	*p;

	if (nmemb == 0 || size == 0)
		return NULL;
	p = malloc(nmemb * size);
	i = -1;
	while (++i < nmemb * size)
		p[i] = '\0';
	return (p);
}

void	ft_strdel(char **s)
{
	if (s == 0)
		return ;
	if (*s)
		free(*s);
	*s = 0;
}