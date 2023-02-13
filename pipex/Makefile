# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cpollito <cpollito@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/02/11 14:43:09 by cpollito          #+#    #+#              #
#    Updated: 2022/02/18 19:18:51 by cpollito         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME		=	pipex

SRC 		=	main.c pipex.c pipex_utils.c ft_split.c

HEADER		=	pipex.h

CC			=	cc

CFLAGS		=	-Wall -Werror -Wextra

OBJS	= $(SRC:c=o)

RM		= rm -rf

.PHONY : all clean fclean re

all:	$(NAME)

%.o:	%.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)	

clean :
	$(RM) $(OBJS)

fclean : clean
	$(RM) $(NAME)
	@$(RM) out*

re : fclean all
