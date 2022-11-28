# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:54:12 by jiwolee           #+#    #+#              #
#    Updated: 2022/11/24 20:28:41 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= my_awsome_phonebook

CXX		= c++
CXXFLAG	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC		= ./main.cpp\
		  ./PhoneBook.cpp\
		  ./Contact.cpp

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
