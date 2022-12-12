/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 23:23:14 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 00:43:09 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Bureaucrat.hpp"
#include	"Form.hpp"
#include	<iostream>
#include	<exception>

Bureaucrat::Bureaucrat( void ) : _name("unknown"), _grade(G_LOWEST){}

Bureaucrat::Bureaucrat( std::string name, int grade ) : _name(name){
	if (grade > G_LOWEST)
		throw GradeTooLowException();
	else if (grade < G_HIGHEST)
		throw GradeTooHighException();
	this->_grade = grade;
}

Bureaucrat::Bureaucrat( Bureaucrat const &origin ) : _name(origin.getName()){
	Bureaucrat::operator=(origin);
}

Bureaucrat::~Bureaucrat( void ){}

Bureaucrat	&Bureaucrat::operator=( Bureaucrat const &origin ){
	this->_grade = origin._grade;
	return *this;
}

std::string	Bureaucrat::getName( void ) const{
	return	this->_name;
}

int	Bureaucrat::getGrade( void ) const{
	return	this->_grade;
}

void	Bureaucrat::incrementGrade( void ){
	if (this->_grade > G_HIGHEST)
		this->_grade--;
	else
		throw GradeTooHighException();
}

void	Bureaucrat::decrementGrade( void ){
	if (this->_grade < G_LOWEST)
		this->_grade++;
	else
		throw GradeTooLowException();
}

const char *Bureaucrat::GradeTooHighException::what( void ) const throw(){
	return	"Grade Too High Exception";
}

const char *Bureaucrat::GradeTooLowException::what( void ) const throw(){
	return	"Grade Too Low Exception";
}

void	Bureaucrat::signForm( Form &f ) const{
	try{
		f.beSigned(*this);
		std::cout << this->_name << " signed " << f.getName() << std::endl;
	}
	catch (std::exception &e){
		std::cout << this->_name << " couldn't signed " << f.getName() \
					<< " because " << e.what() << std::endl;
	}
	catch (...){
		std::cout << "exception" << std::endl;
	}
}

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b ){
	os << b.getName() << ", bureaucrat grade " << b.getGrade() <<".";
	return os;
}
