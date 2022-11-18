# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:54:12 by jiwolee           #+#    #+#              #
#    Updated: 2022/11/18 16:33:12 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= hi_this_is_brain

CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98 -pedantic

#HEADER	= ./Account.hpp

SRC		= ./main.cpp

OBJS	= $(SRC:.cpp=.o)

%.o : %.cpp #$(HEADER)
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
