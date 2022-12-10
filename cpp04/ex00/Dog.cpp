/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:50:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 03:46:30 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"
#include	<iostream>

Dog::Dog( void ){
	this->type = "Dog";
	std::cout << "Dog : default constructor called" << std::endl;
}

Dog::Dog( const Dog &origin ) : Animal() {
	Dog::operator=(origin);
	std::cout << "Dog : copy constructor called" << std::endl;
}

Dog::~Dog( void ){
	std::cout << "Dog : destructor called" << std::endl;
}

Dog	&Dog::operator=( const Dog &origin){
	this->type = origin.getType();
	return *this;
}

void	Dog::makeSound( void ) const{
	std::cout << "Dog : Woof! woof!!" << std::endl;
}
