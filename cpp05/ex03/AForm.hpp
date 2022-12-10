/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/09 00:32:28 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 01:23:34 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
# define AFORM_HPP

# include	<string>

class	Bureaucrat;

class AForm{
private:
	std::string const	_name;
	bool				_signed;
	int const			_grade_sign;
	int const			_grade_execute;
public:
	AForm( void );
	AForm( AForm const &origin);
	AForm( std::string name, int grade_sign, int grade_execute );
	virtual ~AForm( void );
	
	AForm	&operator=( AForm const &origin);

	void		beSigned( Bureaucrat const &b );
	std::string	getName( void ) const;
	bool		getSigned( void ) const;
	int			getGradeS( void ) const;
	int			getGradeE( void ) const;
	virtual void	execute( Bureaucrat const &executor ) const = 0;

	class	GradeTooHighException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
	class	GradeTooLowException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
	class	UnsignedFormException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
};

std::ostream	&operator<<( std::ostream &os, AForm const &f );

#endif
