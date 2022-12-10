/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:37:52 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 03:20:06 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"PresidentialPardonForm.hpp"
#include	"Bureaucrat.hpp"
#include	<iostream>

PresidentialPardonForm::PresidentialPardonForm( void ) : AForm("unknown_form", 25, 5){}

PresidentialPardonForm::PresidentialPardonForm( std::string target ) : AForm(target, 25, 5){}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &origin ){
	PresidentialPardonForm::operator=(origin);
}

PresidentialPardonForm::~PresidentialPardonForm( void ){}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &origin ){
	AForm::operator=(origin);
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const{
	if (this->getSigned() == false)
		throw "form is not signed";
	if (executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();
	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
