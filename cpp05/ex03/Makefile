# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/16 15:54:12 by jiwolee           #+#    #+#              #
#    Updated: 2022/12/11 00:28:25 by jiwolee          ###   ########seoul.kr   #
#                                                                              #
# **************************************************************************** #

NAME	= a.out

CXX		= c++
CXXFLAG	= -Wall -Wextra -Werror -std=c++98 -pedantic

SRC		= ./main.cpp\
		  ./Bureaucrat.cpp\
		  ./AForm.cpp\
		  ./ShrubberyCreationForm.cpp\
		  ./RobotomyRequestForm.cpp\
		  ./PresidentialPardonForm.cpp\
		  ./Intern.cpp

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
