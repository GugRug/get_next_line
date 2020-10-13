/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/10/13 04:14:10 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"

#define BUFFER_SIZE 3

int	ft_isend(char *buf, int rd)
{
	
}

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];
	int	rd, i_test;
	t_list	*lin;
	
	while(rd = read(fd, buf, BUFFER_SIZE > 0) && i_test > 10)
	{
		lin->content = buf;
		lin = lin->next;
		i_test++;
		if(ft_strchr(buf, '\n'))
			break;
	}
	
	//tests
	// char c = rd + '0';
	// write(1, &c, 1);	
	write(1, "\n--\n", 4);
	return(0);
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
		write(1, line, ft_strlen(line));
	}
	write(1, "\n--\n", 4); 		
	write(1, "end\n", 4);
	return(0);
}
