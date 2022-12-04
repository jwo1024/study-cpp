/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongWrongAnimal.hpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:15:16 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 13:42:30 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef WRONGANIMAL_HPP
# define WRONGANIMAL_HPP

#include	<string>

class WrongAnimal{
protected:
	std::string type;
public:
	WrongAnimal( void );
	WrongAnimal( const WrongAnimal &origin );
	virtual ~WrongAnimal( void );

	WrongAnimal	&operator=( const WrongAnimal &origin );

	std::string	getType( void ) const;
	void		makeSound( void ) const;
};

#endif
