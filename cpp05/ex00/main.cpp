/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:40 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 00:41:26 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	<iostream>

int	main( void ){
	
	try
	{
		Bureaucrat	a("jiwoo", 150);
		Bureaucrat	b("minsuuu", 1);
		Bureaucrat	c("Bruno Mars", 3);

		for (int i = 0; i < 149; i++)
			a.incrementGrade();
		for (int i = 0; i < 149; i++)
			b.decrementGrade();

		std::cout << a << std::endl;
		std::cout << b << std::endl;
		std::cout << c << std::endl;

	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	catch (...){
		std::cout << "exception" << std::endl;
	}

	return 0;
}
