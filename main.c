/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/25 22:41:49 by hcastanh          #+#    #+#             */
/*   Updated: 2020/10/20 09:34:54 by gumartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>

int main()
{
	int			fd;
	int			retorno;
	char		*line;

	fd = open("./text.txt", O_RDONLY);
	retorno = get_next_line(fd, &line);

	while(line)
	{
		printf("%s\n", line);
		free(line);
		if (retorno <= 0)
			break;
		retorno = get_next_line(fd, &line);
	}
	close (fd);
	return (retorno);
}
