/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:50:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 03:51:44 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"
#include	<iostream>

Dog::Dog( void ){
	std::cout << "Dog : default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog( Dog const &origin ) :Animal(){
	std::cout << "Dog : copy constructor called" << std::endl;
	Dog::operator=(origin);
}

Dog::~Dog( void ){
	std::cout << "Dog : destructor called" << std::endl;
	delete	this->brain;
}

Dog	&Dog::operator=( Dog const &origin){
	this->type = origin.getType();
	*(this->brain) = *(origin.brain);
	return *this;
}

void	Dog::makeSound( void ) const{
	std::cout << "Dog : Woof! woof!!" << std::endl;
}

Brain	*Dog::getBrain( void ) const{
	return this->brain;
}
