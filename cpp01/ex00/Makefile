# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:54:12 by jiwolee           #+#    #+#              #
#    Updated: 2022/11/30 16:42:21 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= BraiiiiiiinnnzzzZ

CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC		= ./main.cpp\
		  ./Zombie.cpp\
		  ./newZombie.cpp\
		  ./randomChump.cpp

OBJS	= $(SRC:.cpp=.o)

%.o : %.cpp
		$(CC) $(CFLAG) -c -o $@ $^

all : $(NAME)

$(NAME) : $(OBJS)
		$(CC) $(CFLAG) -o $@ $^

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
