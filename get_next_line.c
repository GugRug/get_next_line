/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/31 04:04:34 by gumartin          #+#    #+#             */
/*   Updated: 2020/07/31 04:04:41 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "get_next_line_utils.c"
//DELETE LATER
#include <stdio.h>
#include <fcntl.h>

#define BUFFER_SIZE 9

int	get_next_line(int fd, char **line)
{
	char	buf[BUFFER_SIZE + 1];

	int	rd;
	rd = read(fd, buf, BUFFER_SIZE);
	
	//tests
	write(1, buf, 5); 		
	write(1, "\n--\n", 4);
	char c = rd + '0';
	write(1, &c, 1);	
	return(0);
}


int	main(void)
{
	char **line;
	write(1, "gnl:\n", 5);
	get_next_line(open("text.txt", 0), line);
	write(1, "end\n", 4);
	return(0);
}
