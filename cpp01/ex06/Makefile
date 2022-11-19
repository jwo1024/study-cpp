# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:54:12 by jiwolee           #+#    #+#              #
#    Updated: 2022/11/19 15:50:12 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= harlFilter

CC		= c++
CFLAG	= -Wall -Wextra -Werror -std=c++98 -pedantic

#HEADER	= ./Account.hpp

SRC		= ./main.cpp\
		  ./Harl.cpp

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
