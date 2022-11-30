/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:02:52 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 17:55:59 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include	<string>

class Zombie{
private:
	std::string	name;
public:
	Zombie( const std::string name );
	~Zombie( void );
	void announce( void );
};

Zombie* newZombie( std::string name );

void randomChump( std::string name );

#endif
