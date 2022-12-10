/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:26:46 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 00:40:37 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Intern.hpp"
#include	"AForm.hpp"
#include	"ShrubberyCreationForm.hpp"
#include	"RobotomyRequestForm.hpp"
#include	"PresidentialPardonForm.hpp"
#include	<iostream>
#include	<string>

Intern::Intern( void ){}

Intern::Intern( Intern const &origin ){
	Intern::operator=(origin);
}

Intern::~Intern( void ){}

Intern	&Intern::operator=( Intern const &origin ){
	(void)origin;
	return *this;
}

AForm	*Intern::newShrubberyCreation( std::string &target ) const{
	return new ShrubberyCreationForm(target);
}

AForm	*Intern::newRobotomyRequest( std::string &target ) const{
	return new RobotomyRequestForm(target);
}

AForm	*Intern::newPresidentialPardon( std::string &target ) const{
	return new PresidentialPardonForm(target);
}

AForm	*Intern::makeForm( std::string type, std::string target ) const{
	std::string types[3] = {"shrubbery creation", "robotomy request", "presidential pardon"};
	AForm *(Intern::*func[3])(std::string&) const = {&Intern::newShrubberyCreation, &Intern::newRobotomyRequest, &Intern::newPresidentialPardon};

	for (int i = 0; i < 3; i++)
	{
		if (types[i] == type)
		{
			std::cout << "Intern creates " << type << std::endl;
			return (this->*func[i])(target);
		}
	}
	throw Intern::MismatchedTypeException();
}

const char	*Intern::MismatchedTypeException::what( void ) const throw(){
	return "Mismatched Form Type";
}
