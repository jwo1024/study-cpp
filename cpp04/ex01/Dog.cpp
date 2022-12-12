/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jiwolee <jiwolee@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/03 23:50:11 by jiwolee           #+#    #+#             */
/*   Updated: 2022/12/11 18:27:07 by jiwolee          ###   ########seoul.kr  */
/*                                                                            */
/* ************************************************************************** */

#include	"Dog.hpp"
#include	<iostream>

Dog::Dog( void ){
	std::cout << "Dog : default constructor called" << std::endl;
	this->type = "Dog";
	this->brain = new Brain();
}

Dog::Dog( Dog const &origin ) : Animal(){
	std::cout << "Dog : copy constructor called" << std::endl;
	this->brain = new Brain();
	Dog::operator=(origin);

}

Dog::~Dog( void ){
	std::cout << "Dog : destructor called" << std::endl;
	if (this->brain)
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

Brain const	*Dog::getBrain( void ) const{
	return this->brain;
}

std::string const	Dog::getIdea( int const idx ) const{
	return this->brain->getIdea(idx);
}

void	Dog::setIdea( int const idx, std::string const idea ){
	this->brain->setIdea(idx, idea);
}
