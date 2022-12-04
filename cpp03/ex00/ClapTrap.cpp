/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 11:46:46 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/03 13:59:48 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"ClapTrap.hpp"
#include	<iostream>

ClapTrap::ClapTrap( void )
	: _name("unknown"), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << "Default Constructor called" << std::endl;
}

ClapTrap::ClapTrap( std::string name )
	: _name(name), _hit_points(10), _energy_points(10), _attack_damage(0){
	std::cout << "Param Constructor called : " << this->_name << std::endl;
}

ClapTrap::ClapTrap( ClapTrap const &origin ){
	operator=(origin);
	std::cout << "Copy Constructor called : " << this->_name << std::endl;
}

ClapTrap::~ClapTrap( void ){
	std::cout << "Destrutor called : " << this->_name << std::endl;
}

ClapTrap	&ClapTrap::operator=( ClapTrap const &origin ){
	this->_name = origin.getName();
	this->_hit_points = origin.getHitPoints();
	this->_energy_points = origin.getEnergyPoints();
	this->_attack_damage = origin.getAttackDamage();
	return *this;
}


std::string	ClapTrap::getName( void ) const{
	return this->_name;
}

unsigned int	ClapTrap::getHitPoints( void ) const{
	return this->_hit_points;
}

unsigned int	ClapTrap::getEnergyPoints( void ) const{
	return this->_energy_points;
}

int	ClapTrap::getAttackDamage( void ) const{
	return this->_attack_damage;
}

void	ClapTrap::attack( const std::string& target ){
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't do anything.." << std::endl;
		return ;
	}
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name << " attacks " << target \
				<< ", causing" << this->_attack_damage << "points of damage!" << std::endl;
}

void	ClapTrap::takeDamage( unsigned int amount ){
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't do anything.." << std::endl;
		return ;
	}
	this->_hit_points -= amount;
	std::cout << "ClapTrap " << this->_name << " takes " << amount \
				<< "points of damage! , hp : " << this->_hit_points << std::endl;
}

void	ClapTrap::beRepaired( unsigned int amount ){
	if (this->_hit_points == 0 || this->_energy_points == 0)
	{
		std::cout << "ClapTrap " << this->_name << " can't do anything..." << std::endl;
		return ;
	}
	this->_hit_points += amount;
	this->_energy_points--;
	std::cout << "ClapTrap " << this->_name \
				<< "has been repaired, hp : " << this->_hit_points << std::endl;
}
