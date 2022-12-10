/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:50:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/04 13:34:18 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"WrongCat.hpp"
#include	<iostream>

WrongCat::WrongCat( void ){
	this->type = "WrongCat";
	std::cout << "WrongCat : default constructor called" << std::endl;
}

WrongCat::WrongCat( std::string type ){
	this->type = type;
	std::cout << "WrongCat : param constructor called" << std::endl;
}

WrongCat::WrongCat( const WrongCat &origin ) : WrongAnimal(){
	WrongCat::operator=(origin);
	std::cout << "WrongCat : copy constructor called" << std::endl;
}

WrongCat::~WrongCat( void ){
	std::cout << "WrongCat : destructor called" << std::endl;
}

WrongCat	&WrongCat::operator=( const WrongCat &origin){
	this->type = origin.getType();
	return *this;
}

void	WrongCat::makeSound( void ) const{
	std::cout << "WrongCat : Meow~ Meow~" << std::endl;
}
