/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:47:01 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 13:48:26 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGCAT_HPP
# define WRONGCAT_HPP

#include	"WrongAnimal.hpp"

class WrongCat : public WrongAnimal{
public:
	WrongCat( void );
	WrongCat( std::string type );
	WrongCat( const WrongCat &origin );
	~WrongCat( void );

	WrongCat	&operator=( const WrongCat &origin );
	void	makeSound( void ) const;
};

#endif
