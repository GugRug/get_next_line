# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gumartin <gumartin@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/02/03 18:56:21 by gumartin          #+#    #+#              #
#    Updated: 2020/10/20 11:49:08 by gumartin         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = get_next_line.a
SRCS = main.c get_next_line.c get_next_line_utils.c
SRCS_B = main.c get_next_line_bonus.c get_next_line_utils_bonus.c
OBJS = $(SRCS:.c=.o)
FLAGS = -g -Wall -Wextra -Werror -D BUFFER_SIZE=2
LIB = get_next_line.h 
LIB_B = get_next_line_bonus.h 
	
all:
	gcc $(FLAGS) $(SRCS) -o testevalgrind

leak: 
	gcc $(FLAGS) -fsanitize=address $(SRCS) $(LIB) 

bonus:
	gcc $(FLAGS) -fsanitize=address $(SRCS_B) $(LIB_B) 

clean:
	rm -f $(OBJS) $(OBJS_BONUS)

fclean: clean
	rm -f $(NAME) a.out

re: fclean all

.PHONY: all bonus clean fclean re
