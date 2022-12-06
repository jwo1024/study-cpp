/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   DiamondTrap.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 15:46:49 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 19:47:38 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"DiamondTrap.hpp"
#include	<iostream>

DiamondTrap::DiamondTrap( void ) : ClapTrap(), ScavTrap(), FragTrap(){
	std::cout << "DiamondTrap : Default Constructor called" << std::endl;
	this->_name	= "unknown";
	ClapTrap::_name	= this->_name + "_clap_name";
	ClapTrap::_energy_points = 50;
}

DiamondTrap::DiamondTrap( std::string name ) 
	: ClapTrap(name), ScavTrap(name), FragTrap(name){
	this->_name = name;
	std::cout << "DiamondTrap : Param Constructor called : " << this->_name << std::endl;
	ClapTrap::_name	= this->_name + "_clap_name";
	ClapTrap::_energy_points = 50;
}

DiamondTrap::DiamondTrap( DiamondTrap const &origin ) : ClapTrap(), ScavTrap(), FragTrap(){
	this->_name = origin._name;
	std::cout << "DiamondTrap : Copy Constructor called : " << this->_name << std::endl;
	ClapTrap::operator=(origin);
}

DiamondTrap::~DiamondTrap( void ){
	std::cout << "DiamondTrap : Destrutor called : " << this->_name << std::endl;
}

DiamondTrap	&DiamondTrap::operator=( DiamondTrap const &origin ){
	this->_name = origin._name;
	ClapTrap::operator=(origin);
	return *this;
}

void	DiamondTrap::attack( const std::string& target ){
	ScavTrap::attack(target);
}

void	DiamondTrap::whoAmI( void ){
	std::cout << "Diamond name : [" << this->_name \
				<< "], Clap name :[" << ClapTrap::_name << "]" << std::endl;
}
