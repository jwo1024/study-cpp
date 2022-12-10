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
//#include	<cstdlib>

RobotomyRequestForm::RobotomyRequestForm( void ) : AForm("unknown_form", 72, 45){}

RobotomyRequestForm::RobotomyRequestForm( std::string target ) : AForm(target, 72, 45){}

RobotomyRequestForm::RobotomyRequestForm( RobotomyRequestForm const &origin ){
	RobotomyRequestForm::operator=(origin);
}

RobotomyRequestForm::~RobotomyRequestForm( void ){}

RobotomyRequestForm	&RobotomyRequestForm::operator=( RobotomyRequestForm const &origin ){
	AForm::operator=(origin);
	return *this;
}

void	RobotomyRequestForm::execute( Bureaucrat const &executor ) const{
	if (this->getSigned() == false)
		throw "form is not signed";
	if (executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();
	srand(time(NULL));
	int	a = rand() % 2; // 0 % 2 가 될까
	if (a == 0)
		std::cout << this->getName() << " has been robotomized " << std::endl;
	else
		std::cout << this->getName() << " failed to be robotomized" << std::endl;
}
