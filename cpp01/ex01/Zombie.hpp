/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:02:52 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 18:51:10 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#ifndef	ZOMBIE_HPP
# define ZOMBIE_HPP

#include	<string>

class Zombie{
private:
	std::string	name;
public:
	Zombie( void );
	Zombie( std::string name );
	~Zombie( void );
	
	void	announce( void ) const;
	void	init_name( const std::string name );
};

Zombie*    zombieHorde( int N, std::string name );

#endif
