/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 18:12:43 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 18:34:33 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */


#include	"HumanB.hpp"
#include	<iostream>


HumanB::HumanB(std::string set_name)
	: name(set_name), weapon(NULL){ }

HumanB::~HumanB()
{
	std::cout << this->name << "disappeard" << std::endl;
}

void	HumanB::attack(){
	std::cout << this->name << "attacks with thier " << this->weapon->getType() << std::endl;
}

void	HumanB::setWeapon(Weapon &set_weapon)
{
	this->weapon = &set_weapon;
}
