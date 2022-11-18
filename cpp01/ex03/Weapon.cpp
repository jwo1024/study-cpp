/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:55:16 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/18 17:11:00 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Weapon.hpp"

Weapon::Weapon(/* args */)
{
}

Weapon::Weapon(std::string set_type){	
	this->type = set_type;
}

Weapon::~Weapon()
{
}

std::string Weapon::getType(){
	return (this->type);
}

void Weapon::setType(std::string set_type){
	this->type = set_type;
}
