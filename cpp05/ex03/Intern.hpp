/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 22:26:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 00:30:28 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
# define INTERN_HPP

#include	<string>

class AForm;

class Intern{
private:
	AForm	*newShrubberyCreation( std::string &target ) const;
	AForm	*newRobotomyRequest( std::string &target ) const;
	AForm	*newPresidentialPardon( std::string &target ) const;
public:
	Intern( void );
	Intern( Intern const &origin );
	~Intern( void );

	Intern &operator=( Intern const &origin );

	AForm	*makeForm( std::string type, std::string target ) const;

	class	MismatchedTypeException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
};

#endif
