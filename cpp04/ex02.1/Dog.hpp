/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:47:01 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 17:06:57 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
# define DOG_HPP

#include	"Animal.hpp"
#include	"Brain.hpp"

class Dog : public Animal{
private:
	Brain	*brain;
public:
	Dog( void );
	Dog( Dog const &origin );
	~Dog( void );

	Dog	&operator=( Dog const &origin );

	void	makeSound( void ) const;
	Brain	*getBrain( void ) const;
};

#endif
