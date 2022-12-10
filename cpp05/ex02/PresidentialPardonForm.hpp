/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:28:59 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 03:25:22 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRESIDENTIALPARDONFORM_HPP
# define PRESIDENTIALPARDONFORM_HPP

# include	"AForm.hpp"

class PresidentialPardonForm : public AForm{
private:
	std::string	_target;
public:
	PresidentialPardonForm( void );
	PresidentialPardonForm( std::string target );
	PresidentialPardonForm( PresidentialPardonForm const &origin );
	~PresidentialPardonForm( void );

	PresidentialPardonForm	&operator=( PresidentialPardonForm const &origin );

	void	execute( Bureaucrat const &executor ) const;
};

#endif
