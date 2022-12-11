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

PresidentialPardonForm::PresidentialPardonForm( void )
	: AForm("presidential pardon", 25, 5), _target("unknown_target"){}

PresidentialPardonForm::PresidentialPardonForm( std::string target )
	: AForm("presidential pardon", 25, 5), _target(target){}

PresidentialPardonForm::PresidentialPardonForm( PresidentialPardonForm const &origin ){
	PresidentialPardonForm::operator=(origin);
}

PresidentialPardonForm::~PresidentialPardonForm( void ){}

PresidentialPardonForm	&PresidentialPardonForm::operator=( PresidentialPardonForm const &origin ) : AForm(){
	AForm::operator=(origin);
	this->_target = origin._target;
	return *this;
}

void	PresidentialPardonForm::execute( Bureaucrat const &executor ) const{
	if (this->getSigned() == false)
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();
	std::cout << this->_target << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
