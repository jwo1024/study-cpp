/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:21:37 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:19:55 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Animal.hpp"
#include	<iostream>

Animal::Animal( void ){
	std::cout << "Animal : default constructor called" << std::endl;
}

Animal::Animal( const Animal &origin ){
	operator=(origin);
	std::cout << "Animal : copy constructor called" << std::endl;
}

Animal::~Animal( void ){
	std::cout << "Animal : destructor called" << std::endl;
}

Animal	&Animal::operator=( Animal const &origin ){
	if (this->type == origin.type)
		this->type = origin.type;
	else
		std::cout << "operator= : not same type" <<std::endl;
	return *this;
}

std::string	Animal::getType( void ) const{
	return this->type;
}

void	Animal::makeSound( void ) const{
	std::cout << "Animal : just animal... " << std::endl;
}
