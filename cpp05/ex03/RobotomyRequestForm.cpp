/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:37:52 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 03:20:06 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"RobotomyRequestForm.hpp"
#include	"Bureaucrat.hpp"
#include	<iostream>
#include	<cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void )
	: AForm("robotomy request", 72, 45), _target("unknown_target"){}

RobotomyRequestForm::RobotomyRequestForm( std::string target )
	: AForm("robotomy request", 72, 45), _target(target){}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &origin ){
	RobotomyRequestForm::operator=(origin);
}

RobotomyRequestForm::~RobotomyRequestForm( void ){}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &origin ) : AForm(){
	AForm::operator=(origin);
	this->_target = origin._target;
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const{
	if (this->getSigned() == false)
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();
	srand(time(NULL));
	if (rand() % 2 == 0)
		std::cout << this->_target << " has been robotomized " << std::endl;
	else
		std::cout << this->_target << " failed to be robotomized" << std::endl;
}
