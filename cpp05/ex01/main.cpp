/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:40 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 00:50:07 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"Form.hpp"
#include	<iostream>

int	main( void ){

	try
	{
		Bureaucrat	a("person_G5", 5);
		Form		form1("top_secret", G_HIGHEST, G_HIGHEST);
		Form		form2("just_form", G_LOWEST, G_LOWEST);

		a.signForm(form1);
		a.signForm(form2);

		for (int i = 0; i < 4; i++)
			a.incrementGrade();
		a.signForm(form1);
	
		std::cout << a << std::endl;
		std::cout << form1 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException	&e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooLowException &e)
	{
		std::cout << e.what() << std::endl;
	}
	catch (Form::GradeTooHighException &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
