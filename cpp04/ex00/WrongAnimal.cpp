/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:21:37 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 13:56:07 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"WrongAnimal.hpp"
#include	<iostream>

WrongAnimal::WrongAnimal( void ){
	std::cout << "WrongAnimal : default constructor called" << std::endl;
}

WrongAnimal::WrongAnimal( const WrongAnimal &origin ){
	operator=(origin);
	std::cout << "WrongAnimal : copy constructor called" << std::endl;
}

WrongAnimal::~WrongAnimal( void ){
	std::cout << "WrongAnimal : destructor called" << std::endl;
}

WrongAnimal	&WrongAnimal::operator=( const WrongAnimal &origin ){
	this->type = origin.getType();
	return *this;
}

std::string	WrongAnimal::getType( void ) const{
	return this->type;
}

void	WrongAnimal::makeSound( void ) const{
	std::cout << "WrongAnimal : just Wrong animal ... " << std::endl;
}
