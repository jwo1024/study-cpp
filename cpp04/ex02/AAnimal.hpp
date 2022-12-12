/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:15:16 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:33:06 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef AANIMAL_HPP
# define AANIMAL_HPP

#include	<string>

class AAnimal{
protected:
	std::string type;
public:
	AAnimal( void );
	AAnimal( const AAnimal &origin );
	virtual ~AAnimal( void );

	AAnimal	&operator=( const AAnimal &origin );

	std::string		getType( void ) const;
	virtual void	makeSound( void ) const = 0;
};

#endif
