/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanA.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:03:35 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 19:16:13 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"HumanA.hpp"
#include	<iostream>

HumanA::HumanA( std::string set_name, Weapon &set_weapon ) 
	: name(set_name), weapon(set_weapon){}

HumanA::~HumanA( void ){
	std::cout << this->name << "disappeard" << std::endl;
}

void	HumanA::attack( void ) const{
	std::cout << this->name << "attacks with thier " << this->weapon.getType() << std::endl;
}

void	HumanA::setWeapon( Weapon &set_weapon ){
	this->weapon = set_weapon;
}
