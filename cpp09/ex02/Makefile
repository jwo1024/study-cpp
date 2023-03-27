# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:54:12 by jiwolee           #+#    #+#              #
#    Updated: 2023/03/16 20:54:02 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= PMergeMe

CXX		= c++
CXXFLAG	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC		= ./main.cpp \
		  ./PmergeMe.cpp

OBJS	= $(SRC:.cpp=.o)

%.o : %.cpp
		$(CXX) $(CXXFLAG) -c -o $@ $^

all : $(NAME)

$(NAME) : $(OBJS)
		$(CXX) $(CXXFLAG) -o $@ $^

clean :
		rm -f $(OBJS)

fclean : clean
		rm -f $(NAME)

re : fclean all

.PHONY : all clean fclean re
