/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/15 06:11:24 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BUFFER_SIZE 6

int	get_next_line(int fd, char **line)
{
	static char	*s_line;
	char	*buf;
	int	rd, i_test;
	
	i_test = 0;
	if (fd < 0 || !(line) || BUFFER_SIZE < 1)
		return (-1);
	buf = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char));								//malloc buf 1
	ft_strclean(buf, ft_strlen(buf));
	if (!(s_line))
		s_line = (char*)malloc((BUFFER_SIZE + 1) * sizeof(char*));						//malloc s_line 2
	while ((rd = read(fd, buf, BUFFER_SIZE > 0)) && !(ft_strchr(s_line, '\n')) && i_test < 10)
	{
		write(1, "\n-2-\n", 4); 	
		ft_putbuf(buf, s_line);
		i_test++;
		if(ft_strchr(s_line, '\n'))
			break;
	}
	ft_puts_line(s_line, line);
	free(buf);													//buf free 1	
	free(s_line);												//s_line free 2
	//tests
	write(1, "\n-1-\n", 4);
	return(0);
}

void	ft_putbuf(char *buf, char *s_line)
{
	char *bn;
	char *cpy;
	int p;

	if ((bn = ft_strchr(buf, '\n')))
		p = buf - bn;
	else
		p = ft_strlen(buf);
	cpy = (char*)malloc((p + 1)* sizeof(char*));				//malloc cpy 3
	ft_strlcpy(cpy, buf, p);
	s_line = ft_strjoin(s_line, cpy);
	if (ft_strchr(buf, '\n')){
		free(cpy);													//cpy free 3
	write(1, "\n-4-\n", 4); }		
}

void	ft_puts_line(char *s_line, char **line)
{
	//put s_line in line, than free s_line pointing to '\n'
	int	i;
	int	pbn;
	
	i = 0;
	pbn = ft_strlen(s_line);
	if (ft_strchr(s_line, '\n'))
		pbn = ft_strchr(s_line, '\n') - s_line;	
	ft_strlcpy(*line, s_line, pbn + 1);
	while (i < pbn)
	{
		s_line++;
		i++;
	}
}


/*
TEST
*/

int	main(void)
{
	int	i = 0;
	char *line;
	write(1, "gnl:\n", 5);
	for(i = 0; i < 3; i++)
	{
		get_next_line(open("text.txt", 0), &line); 
		write(1, "\n-3-\n", 4); 	
		line[1] = 'B';
		printf("\nLine is: %s ---\n", line);
		write(1, line, (ft_strlen(line)));
	}
	write(1, "end\n", 4);
	return(0);
}
