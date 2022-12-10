/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:40 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/09 00:18:39 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	<iostream>

int	main( void ){
	
	try
	{
		Bureaucrat	a("jiwoo", 150);
		Bureaucrat	b("minsuuu", 1);
		Bureaucrat	c("Bruno Mars", 3); // 3->0 exception

		for (int i = 0; i < 149; i++) // 149->150 exception
			a.incrementGrade();
		for (int i = 0; i < 149; i++) // 149->150 exception
			b.decrementGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

	}
	catch (Bureaucrat::GradeTooLowException	&e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	
	return 0;
}
