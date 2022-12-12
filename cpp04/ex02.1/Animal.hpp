/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:15:16 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 21:14:49 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef ANIMAL_HPP
# define ANIMAL_HPP

#include	<string>

class Animal{
protected:
	std::string type;
public:
	Animal( void );
	Animal( const Animal &origin );
	virtual ~Animal( void );

	Animal	&operator=( const Animal &origin );

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;
};

#endif
