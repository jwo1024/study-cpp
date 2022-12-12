/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:51:28 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 00:52:13 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Form.hpp"
#include	"Bureaucrat.hpp"
#include	<iostream>
#include	<exception>

Form::Form( void ) 
	: _name("unknown_form"), _signed(false), _grade_sign(G_LOWEST), _grade_execute(G_LOWEST){}

Form::Form( Form const &origin )
	: _name(origin._name), _signed(origin._signed), _grade_sign(origin._grade_sign), _grade_execute(origin._grade_execute){}

Form::Form( std::string name, int grade_sign, int grade_execute ) 
	: _name(name), _signed(false), _grade_sign(grade_sign), _grade_execute(grade_execute){
	if (this->_grade_sign > G_LOWEST || this->_grade_execute > G_LOWEST)
		throw Form::GradeTooLowException();
	else if (this->_grade_sign < G_HIGHEST || this->_grade_execute < G_HIGHEST)
		throw Form::GradeTooHighException();
}

Form::~Form( void ){}

Form	&Form::operator=( Form const &origin ){
	const_cast<std::string&>(this->_name) = origin._name;
	this->_signed = origin._signed;
	const_cast<int&>(this->_grade_sign) = origin._grade_sign;
	const_cast<int&>(this->_grade_execute) = origin._grade_execute;
	return *this;
}


void	Form::beSigned( Bureaucrat const &b ){
	if (b.getGrade() > this->_grade_sign)
		throw Form::GradeTooLowException();
	this->_signed = true;
}

std::string	Form::getName( void ) const{
	return this->_name;
}

bool	Form::getSigned( void ) const{
	return this->_signed;
}

int	Form::getGradeS( void ) const{
	return this->_grade_sign;
}

int	Form::getGradeE( void ) const{
	return this->_grade_execute;
}

const char *Form::GradeTooHighException::what( void ) const throw(){
	return	"Grade Too High";
}

const char *Form::GradeTooLowException::what( void ) const throw(){
		return	"Grade Too Low";
}


std::ostream	&operator<<( std::ostream &os, Form const &f ){
	if (f.getSigned() == true)
		os << f.getName() << " : signed";
	else
		os << f.getName() << " : unsigned";
	os << ", grade-required-sign : " << f.getGradeS() \
		<< ", grade-required-execute : " << f.getGradeE() << ".";
	return os;
}
