/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 13:52:29 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 15:40:49 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"FragTrap.hpp"
#include	<iostream>

FragTrap::FragTrap( void ){
	this->_name = "unknown";
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap : Default Constructor called" << std::endl;
}

FragTrap::FragTrap( std::string name ) : ClapTrap(name){
	this->_hit_points = 100;
	this->_energy_points = 100;
	this->_attack_damage = 30;
	std::cout << "FragTrap : Param Constructor called : " << this->_name << std::endl;
}

FragTrap::FragTrap( FragTrap const &origin ) : ClapTrap(origin.getName()){
	this->_hit_points = origin.getHitPoints();
	this->_energy_points = origin.getEnergyPoints();
	this->_attack_damage = origin.getAttackDamage();
	std::cout << "FragTrap : Copy Constructor called : " << this->_name << std::endl;
}

FragTrap::~FragTrap( void ){
	std::cout << "FragTrap : Destrutor called : " << this->_name << std::endl;
}

FragTrap	&FragTrap::operator=( FragTrap const &origin ){
	this->_name = origin.getName();
	this->_hit_points = origin.getHitPoints();
	this->_energy_points = origin.getEnergyPoints();
	this->_attack_damage = origin.getAttackDamage();
	return *this;
}

void	FragTrap::attack( const std::string& target ){
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "FragTrap " << this->_name << " can't do anything.." << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << "FragTrap " << this->_name << " attacks " << target \
				<< ", causing" << this->_attack_damage << "points of damage!" << std::endl;

}

void	FragTrap::hiFivesGuys( void ){
	std::cout << "Give " << this->_name << " a poistive high-five!" << std::endl;
}
