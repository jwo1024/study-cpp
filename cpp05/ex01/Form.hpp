/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:32:28 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 00:59:37 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
# define FORM_HPP

# include	<string>

class	Bureaucrat;

class Form{
private:
	std::string const	_name;
	bool				_signed;
	int const			_grade_sign;
	int const			_grade_execute;
public:
	Form( void );
	Form( Form const &origin);
	Form( std::string name, int grade_sign, int grade_execute );
	~Form( void );
	
	Form	&operator=( Form const &origin);

	void		beSigned( Bureaucrat const &b );
	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getGradeS( void ) const;
	int			getGradeE( void ) const;

	class	GradeTooHighException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
	class	GradeTooLowException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
};

std::ostream	&operator<<( std::ostream &os, Form const &f );

#endif
