/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:52:29 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 14:47:57 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ScavTrap.hpp"
#include	<iostream>

ScavTrap::ScavTrap( void ){
	std::cout << "ScavTrap : Default Constructor called" << std::endl;
	this->_name = "unknown";
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( std::string name ) : ClapTrap(name){
	std::cout << "ScavTrap : Param Constructor called : " << this->_name << std::endl;
	this->_hit_points = 100;
	this->_energy_points = 50;
	this->_attack_damage = 20;
}

ScavTrap::ScavTrap( ScavTrap const &origin ) : ClapTrap(origin.getName()){
	std::cout << "ScavTrap : Copy Constructor called : " << this->_name << std::endl;
	this->_hit_points = origin.getHitPoints();
	this->_energy_points = origin.getEnergyPoints();
	this->_attack_damage = origin.getAttackDamage();
}

ScavTrap::~ScavTrap( void ){
	std::cout << "ScavTrap : Destrutor called : " << this->_name << std::endl;
}

ScavTrap	&ScavTrap::operator=( ScavTrap const &origin ){
	this->_name = origin.getName();
	this->_hit_points = origin.getHitPoints();
	this->_energy_points = origin.getEnergyPoints();
	this->_attack_damage = origin.getAttackDamage();
	return *this;
}

void	ScavTrap::attack( const std::string& target ){
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ScavTrap " << this->_name << " can't do anything.." << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << "ScavTrap " << this->_name << " attacks " << target \
				<< ", causing" << this->_attack_damage << "points of damage!" << std::endl;

}

void	ScavTrap::guardGate( void ){
	std::cout << "ScavTrap " << this->_name << " is now in Gate keeper mode." << std::endl;
}
