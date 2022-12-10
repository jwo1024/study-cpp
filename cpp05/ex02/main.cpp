/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:39:40 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 11:55:49 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"
#include	<iostream>

int	main( void ){

	try{
		Bureaucrat	a("Jiwoo", 140);
		Bureaucrat	b("Minsuuu", 45);
		Bureaucrat	c("Zaphod", 1);

		ShrubberyCreationForm	form1("Top_secret");
		RobotomyRequestForm		form2("Robo");
		PresidentialPardonForm	form3("Pardon");

		a.signForm(form1);
		a.executeForm(form1);
		b.executeForm(form1);

		a.signForm(form2);
		b.signForm(form2);
		b.executeForm(form2);
	
		a.signForm(form3);
		b.signForm(form3);
		c.signForm(form3);
		c.executeForm(form3);

		std::cout << form1 << std::endl;
		std::cout << form2 << std::endl;
		std::cout << form3 << std::endl;
	}
	catch (Bureaucrat::GradeTooLowException	&e){
		std::cout << e.what() << std::endl;
	}
	catch (Bureaucrat::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooLowException &e){
		std::cout << e.what() << std::endl;
	}
	catch (AForm::GradeTooHighException &e){
		std::cout << e.what() << std::endl;
	}

	return 0;
}
