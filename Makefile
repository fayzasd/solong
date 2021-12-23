# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fasad <fasad@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/12/22 11:31:34 by fasad             #+#    #+#              #
#    Updated: 2021/12/22 23:24:53 by fasad            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME		= solong.out

SRCS		= solong.c \

FLAGS		= -Wall -Werror -Wextra

CC			= gcc

OBJS		= *.o

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(OBJS) -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)

$(OBJS): $(SRC)
	gcc $(FLAGS) -c $(SRCS)

clean:
		rm -f $(OBJS)

fclean:	clean
		rm -f $(NAME)

re: fclean all

