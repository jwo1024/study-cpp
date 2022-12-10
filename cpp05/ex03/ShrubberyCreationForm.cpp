/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:37:52 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 00:14:03 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ShrubberyCreationForm.hpp"
#include	"Bureaucrat.hpp"
#include	<fstream>

ShrubberyCreationForm::ShrubberyCreationForm( void )
	: AForm("shrubbery creation", 145, 137), _target("unknown_target"){}

ShrubberyCreationForm::ShrubberyCreationForm( std::string target )
	: AForm("shrubbery creation", 145, 137), _target(target){}

ShrubberyCreationForm::ShrubberyCreationForm( ShrubberyCreationForm const &origin ){
	ShrubberyCreationForm::operator=(origin);
}

ShrubberyCreationForm::~ShrubberyCreationForm( void ){}

ShrubberyCreationForm	&ShrubberyCreationForm::operator=( ShrubberyCreationForm const &origin ){
	AForm::operator=(origin);
	this->_target = origin._target;
	return *this;
}

void	ShrubberyCreationForm::execute( Bureaucrat const &executor ) const{
	std::ofstream	write_file;

	if (this->getSigned() == false)
		throw AForm::UnsignedFormException();
	if (executor.getGrade() > this->getGradeE())
		throw AForm::GradeTooLowException();
	write_file.open(this->_target + "_shrubbery");
	if (write_file.fail())
		throw "failed to open write_file";
	write_file << "               ,@@@@@@@," << std::endl;
	write_file << "       ,,,.   ,@@@@@@/@@,  .oo8888o." << std::endl;
	write_file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o" << std::endl;
	write_file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'" << std::endl;
	write_file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'" << std::endl;
	write_file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'" << std::endl;
	write_file << "   `&%\\ ` /%&'    |.|        \\ '|8'" << std::endl;
	write_file << "       |o|        | |         | |" << std::endl;
	write_file << "       |.|        | |         | |" << std::endl;
	write_file << "jgs \\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_" << std::endl;
	write_file.close();
}
