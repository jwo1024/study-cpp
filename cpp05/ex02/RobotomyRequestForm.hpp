/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.hpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/10 01:28:59 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/10 03:07:09 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ROBOTOMYREQUESTFORM_HPP
# define ROBOTOMYREQUESTFORM_HPP

# include	"AForm.hpp"

class RobotomyRequestForm : public AForm{
private:
	std::string	_target;
public:
	RobotomyRequestForm( void );
	RobotomyRequestForm( std::string target );
	RobotomyRequestForm( RobotomyRequestForm const &origin );
	~RobotomyRequestForm( void );

	RobotomyRequestForm	&operator=( RobotomyRequestForm const &origin );

	void	execute( Bureaucrat const &executor ) const;
};

#endif
