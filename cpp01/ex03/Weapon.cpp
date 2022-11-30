/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/18 16:55:16 by jiwolee           #+#    #+#             */
/*   Updated: 2022/11/30 19:01:12 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Weapon.hpp"

Weapon::Weapon( void ){}

Weapon::Weapon( std::string set_type ){	
	this->type = set_type;
}

Weapon::~Weapon( void ){}

const std::string &Weapon::getType( void ) const{
	return (this->type);
}

void Weapon::setType( std::string set_type ){
	this->type = set_type;
}
