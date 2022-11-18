/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:02:52 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 15:22:47 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	<string>

class Zombie
{
private:
	std::string	name;
public:
//	Zombie(); // 있어야하나?
	Zombie(std::string name);
	~Zombie();
	void announce( void );
};


Zombie* newZombie( std::string name );

void randomChump( std::string name );

