/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:40 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 00:56:28 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"
#include	"Intern.hpp"
#include	<iostream>

int	main( void ){

	try{
		Intern intern;
		AForm	*form;
		Bureaucrat	b("b", 10);

		form = intern.makeForm("robotomy request", "target");

		b.executeForm(*form);
		b.signForm(*form);
		b.executeForm(*form);
		delete	form;

		form = intern.makeForm("hello world ", "target");

		delete form;
	}
	catch (std::exception &e){
		std::cout << e.what() << std::endl;
	}
	catch (...){
		std::cout << "exception" << std::endl;
	}

	return 0;
}
