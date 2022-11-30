/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 15:07:55 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 17:56:58 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Zombie.hpp"
#include	<iostream>

Zombie::Zombie( void ){}

Zombie::Zombie( std::string name ){
	this->name = name;
}

Zombie::~Zombie( void ){
	std::cout << this->name << ": destroyed" << std::endl;
}

void Zombie::announce( void ) const{
	std::cout << this->name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}

void Zombie::init_name( const std::string name ){
	this->name = name;
}
