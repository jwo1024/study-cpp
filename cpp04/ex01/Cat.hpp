/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:47:01 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:18:45 by jiwolee          ###   ########seoul.kr  */
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
	std::string const	getIdea( int const idx ) const;
	void				setIdea( int const idx, std::string const idea );
};

#endif
