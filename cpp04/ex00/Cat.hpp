/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:47:01 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 13:56:54 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include	"Animal.hpp"

class Cat : public Animal{
public:
	Cat( void );
	Cat( const Cat &origin );
	~Cat( void );

	Cat	&operator=( const Cat &origin );

	void	makeSound( void ) const;
};

#endif
