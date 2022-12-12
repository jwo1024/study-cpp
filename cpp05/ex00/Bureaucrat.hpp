/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 22:13:17 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/09 00:22:32 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
# define BUREAUCRAT_HPP

# include	<string>
# include	<exception>

# define	G_HIGHEST	1
# define	G_LOWEST	150

class Bureaucrat{
private:
	std::string	const	_name;
	int					_grade;
public:
	Bureaucrat( void );
	Bureaucrat( std::string	name, int grade );
	Bureaucrat( Bureaucrat const &origin );
	~Bureaucrat( void );

	Bureaucrat	&operator=( Bureaucrat const &origin );

	std::string	getName( void ) const;
	int			getGrade( void ) const;
	void		incrementGrade( void );
	void		decrementGrade( void );

	class	GradeTooHighException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
	class	GradeTooLowException : public std::exception{
		public:
			const char *what( void ) const throw();
	};
};

std::ostream	&operator<<( std::ostream &os, Bureaucrat const &b );

#endif
