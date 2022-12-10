/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:28:59 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 04:17:55 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef SHRUBBERYCREATIONFORM_HPP
# define SHRUBBERYCREATIONFORM_HPP

# include	"AForm.hpp"

class ShrubberyCreationForm : public AForm{
private:
	std::string	_target;
public:
	ShrubberyCreationForm( void );
	ShrubberyCreationForm( std::string target );
	ShrubberyCreationForm( ShrubberyCreationForm const &origin );
	~ShrubberyCreationForm( void );

	ShrubberyCreationForm	&operator=( ShrubberyCreationForm const &origin );

	void	execute( Bureaucrat const &executor ) const;
};

#endif
