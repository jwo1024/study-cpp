/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AAnimal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:21:37 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/12 10:19:55 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"AAnimal.hpp"
#include	<iostream>

AAnimal::AAnimal( void ){
	std::cout << "AAnimal : default constructor called" << std::endl;
}

AAnimal::AAnimal( const AAnimal &origin ){
	operator=(origin);
	std::cout << "AAnimal : copy constructor called" << std::endl;
}

AAnimal::~AAnimal( void ){
	std::cout << "AAnimal : destructor called" << std::endl;
}

AAnimal	&AAnimal::operator=( AAnimal const &origin ){
	this->type = origin.type;
	return *this;
}

std::string	AAnimal::getType( void ) const{
	return this->type;
}
