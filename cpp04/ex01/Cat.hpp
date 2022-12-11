/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:47:01 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 16:34:26 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
# define CAT_HPP

#include	"Animal.hpp"
#include	"Brain.hpp"

class Cat : public Animal{
private:
	Brain	*brain;
public:
	Cat( void );
	Cat( Cat const &origin );
	~Cat( void );

	Cat	&operator=( Cat const &origin );

	void	makeSound( void ) const;
	Brain	*getBrain( void ) const;
};

#endif
